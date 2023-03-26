#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

void mirror(TreeNode* root) {
    if (!root) {
        return;
    }
    
    mirror(root->left);
    mirror(root->right);
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Original tree: ";
    cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->left->left->val << " " << root->left->right->val << endl;
    
    mirror(root);
    
    cout << "Mirror image: ";
    cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->right->left->val << " " << root->right->right->val << endl;
    
    return 0;
}
