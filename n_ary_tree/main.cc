#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

struct TreeNode {
	int value;
	std::vector<TreeNode *> children;

	TreeNode(int val) : value(val) {}
};

class NaryTree {
	public:
		TreeNode* root;

		NaryTree() : root(nullptr) {}

		TreeNode* insert_node(int val, TreeNode* parent = nullptr) {
			TreeNode* newNode = new TreeNode(val);

			// 当未指定父节点时，新节点就默认为根节点
			// 如果指定了父节点，就将父节点作为跟节点的子节点插入
			if (parent == nullptr) root = newNode;
			else parent->children.push_back(newNode);

			return newNode;
		}

		// 递归删除当前节点下的所有子节点以及自身
		void deleteSubtree (TreeNode* node) {
			if (node == nullptr) return;

			for (TreeNode* child : node->children) {
				deleteSubtree(child);
			}

			delete node;
		}

		// 先序遍历 (root -> child)
		void preorder_traversal(TreeNode* node) {
			if (node == nullptr) return;

			std::cout << node->value << " ";
			for (TreeNode* child : node->children) {
				preorder_traversal(child);
			}
		}

		// 后序遍历 (child -> root)
		void postorder_traversal(TreeNode* node) {
			if (node == nullptr) return;
			for (TreeNode* child : node->children) {
				postorder_traversal(child);
			}

			std::cout << node->value << " ";
		}
};

int main() {

	NaryTree tree;

	TreeNode* root = tree.insert_node(1);
	TreeNode* child1 = tree.insert_node(2, root);
	TreeNode* child2 = tree.insert_node(3, root);
	TreeNode* grandchild1 = tree.insert_node(4, child1);
	TreeNode* grandchild2 = tree.insert_node(5, child1);

	std::cout << "Preorder traversal: ";
	tree.preorder_traversal(root);
	std::cout << std::endl;

	std::cout << "Postorder traversal: ";
	tree.postorder_traversal(root);
	std::cout << std::endl;

	tree.deleteSubtree(root);
	return 0;
}
