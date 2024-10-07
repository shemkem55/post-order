class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if (node->left) {
            stack.push(node->left);
        }
        if (node->right) {
            stack.push(node->right);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}