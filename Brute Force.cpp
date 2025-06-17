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
    int ans = 0;  // Variable to store the final sum of node values within the range

    // Helper function to traverse the tree and accumulate sum
    void traversal(TreeNode* root, int low, int high) {
        if (!root) return;  // Base case: if node is null, do nothing

        // If the current node's value is within [low, high], add it to the sum
        if (root->val >= low && root->val <= high) {
            ans += root->val;
        }

        // Recursively traverse the left and right subtrees
        traversal(root->left, low, high);
        traversal(root->right, low, high);
    }

    // Main function to be called with the root and range limits
    int rangeSumBST(TreeNode* root, int low, int high) {
        traversal(root, low, high);  // Start DFS traversal
        return ans;  // Return the computed sum
    }
};
