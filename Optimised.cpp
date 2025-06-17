/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;  // Variable to store the sum of node values within the given range

    // Recursive helper function to perform optimized traversal
    void traversal(TreeNode* root, int low, int high) {
        if (!root) return;  // Base case: if node is null, stop recursion

        // If current node's value is within range, include it in the sum
        if (root->val >= low && root->val <= high) {
            ans += root->val;
        }

        // If current node value is greater than or equal to low, 
        // left subtree may have nodes within range → recurse left
        if (root->val >= low) {
            traversal(root->left, low, high);
        }

        // If current node value is less than or equal to high,
        // right subtree may have nodes within range → recurse right
        if (root->val <= high) {
            traversal(root->right, low, high);
        }
    }

    // Main function to calculate sum of values in BST within given range [low, high]
    int rangeSumBST(TreeNode* root, int low, int high) {
        traversal(root, low, high);  // Start the traversal from root
        return ans;  // Return the computed sum
    }
};
