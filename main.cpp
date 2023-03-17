#include <iostream>

using namespace std;

struct Node{
    int key;
    int left;
    int right;
};


class BST {
private:
    Node nodes[1000000];
    int size;
public:
    BST() {
        size = 0;
    }

    void insert(int key) {
        if (size == 0) {
            size++;
            nodes[size] = {key, -1, -1};
            return;
        }

        Node *curr = &nodes[1];
        while (true) {
            if (curr->key > key) {
                if (curr->left == -1) {
                    size++;
                    nodes[size] = {key, -1, -1};
                    curr->left = size;
                    break;
                }
                curr = &nodes[curr->left];
            }
            else {
                if (curr->right == -1) {
                    size++;
                    nodes[size] = {key, -1, -1};
                    curr->right = size;
                    break;
                }
                curr = &nodes[curr->right];
            }
        }
    }

    void print() {
        cout << size << endl;
        for (int i = 1; i <= size; ++i) {
            cout << nodes[i].key << ' ' << nodes[i].left << ' ' << nodes[i].right << endl;
        }
        cout << 1 << endl;
    }
};

int main() {
    int n, x;
    BST tree;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        tree.insert(x);
    }
    tree.print();
    return 0;
}