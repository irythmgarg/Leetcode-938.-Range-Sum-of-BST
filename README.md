# Leetcode-938.-Range-Sum-of-BST
# 🌳 Range Sum of BST (Binary Search Tree)

## 🧩 Problem Statement

Given the root of a Binary Search Tree (BST) and two integers `low` and `high`, return the **sum of values** of all nodes with a value in the inclusive range `[low, high]`.

### 💡 Example:

```
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are within range and their sum is 32.
```

---

## 🔍 Approaches

### 🟢 1. Brute Force DFS Traversal (Without Optimization)

* **Idea**: Traverse all nodes of the BST and add the node's value to the result if it lies in the range `[low, high]`.
* **Time Complexity**: O(n), where `n` is the number of nodes.
* **Space Complexity**: O(h), where `h` is the height of the tree (due to recursion stack).
* **Use Case**: Works correctly, but doesn't use BST properties for pruning.

```cpp
void traversal(TreeNode* root, int low, int high) {
    if (!root) return;
    if (root->val >= low && root->val <= high) {
        ans += root->val;
    }
    traversal(root->left, low, high);
    traversal(root->right, low, high);
}
```

---

### 🔵 2. Optimized DFS Using BST Properties

* **Idea**: Utilize the BST property:

  * If `root->val < low`, all nodes in left subtree are smaller and can be skipped.
  * If `root->val > high`, all nodes in right subtree are greater and can be skipped.
* **Time Complexity**: Better than O(n) in practice due to pruning.
* **Space Complexity**: O(h)
* **Use Case**: More efficient for large BSTs with irrelevant branches.

```cpp
void traversal(TreeNode* root, int low, int high) {
    if (!root) return;
    if (root->val >= low && root->val <= high) {
        ans += root->val;
    }
    if (root->val >= low) traversal(root->left, low, high);
    if (root->val <= high) traversal(root->right, low, high);
}
```

---

## 🧠 Comparison

| Approach        | Time Complexity   | Space Complexity | Uses BST Property | Notes                       |
| --------------- | ----------------- | ---------------- | ----------------- | --------------------------- |
| Brute Force DFS | O(n)              | O(h)             | ❌                 | Traverses all nodes         |
| Optimized DFS   | \~O(n) but faster | O(h)             | ✅                 | Prunes unnecessary branches |

---

## 👨‍💻 Author Info

**Name:** Ridham Garg
**University:** Thapar Institute of Engineering and Technology, Patiala
**Roll Number:** 102203014
**Motto:** Optimize everything, even your recursion! 🔁🌲
