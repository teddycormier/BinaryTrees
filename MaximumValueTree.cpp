#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

int find_max(TreeNode* root) {
    if (!root) {
        return INT_MIN;
    }
    
    int left_max = find_max(root->left);
    int right_max = find_max(root->right);
    
    return max(root->val, max(left_max, right_max));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    int max_val = find_max(root);
    cout << "Maximum value in the tree: " << max_val << endl;
    
    return 0;
}
