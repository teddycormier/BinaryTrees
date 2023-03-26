#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

bool is_identical_tree(TreeNode* tree1, TreeNode* tree2) {
    if (!tree1 && !tree2) {
        return true;
    }
    
    if (!tree1 || !tree2) {
        return false;
    }
    
    if (tree1->val != tree2->val) {
        return false;
    }
    
    return is_identical_tree(tree1->left, tree2->left) && is_identical_tree(tree1->right, tree2->right);
}

int main() {
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->left = new TreeNode(4);
    tree1->left->right = new TreeNode(5);
    
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->left->left = new TreeNode(4);
    tree2->left->right = new TreeNode(6);
    
    if (is_identical_tree(tree1, tree2)) {
        cout << "The two trees are identical" << endl;
    } else {
        cout << "The two trees are not identical" << endl;
    }
    
    return 0;
}
