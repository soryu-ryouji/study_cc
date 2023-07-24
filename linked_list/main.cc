#include <iostream>

struct Node {
	int data;
	Node* next;

	Node(int value): data(value), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList(): head(nullptr) {}

	// 在链表的末尾添加新节点
	void append(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* curNode = head;
			while (curNode->next != nullptr) {
				curNode = curNode->next;
			}
			curNode->next = newNode;
		}
	}

	// 在链表的头部插入新节点
	void prepend(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	// 删除特定值的节点
	void remove(int value) {
		if (head == nullptr) return;

		if (head->data == value) {
			Node* tempNode = head;
			head = head->next;
			delete tempNode;

			return;
		}

		Node* curNode = head;
		while (curNode->next != nullptr) {
			if (curNode->next->data == value) {
				Node* tempNode = curNode->next;
				curNode->next = curNode->next->next;
				delete tempNode;

				return;
			}
		}
	}

	// 打印链表内容
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
	

	// 清空链表内容
	void clear() {
        Node* curNode = head;
        while (curNode != nullptr) {
            Node* temp = curNode;
            curNode = curNode->next;
            delete temp;
        }

        head = nullptr;
    }

	~LinkedList() {
        clear();
    }
};

int main() {
	LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.display();

	std::cout << "........." << std::endl;

	list.remove(20);
	list.display();

	std::cout << "........." << std::endl;

    list.clear();
    list.display();

	return 0;
}
