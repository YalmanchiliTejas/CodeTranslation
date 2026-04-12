#include <cstdio>
#include <cstring>

typedef struct Node {
    int k;
    int p;
    struct Node *left;
    struct Node *right;
} Node;

Node *getNewNode(int k, int p){
    static int i = 0;
    static Node node[200000];
    node[i].k = k;
    node[i].p = p;
    node[i].left = nullptr;
    node[i].right = nullptr;
    return &node[i++];
}

Node *rightRotate(Node *t){
    Node *s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node *leftRotate(Node *t){
    Node *s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node *insert(Node *t, int k, int p){
    if(t == nullptr){
        return getNewNode(k, p);
    } else if(k < t->k){
        t->left = insert(t->left, k, p);
        if(t->p < t->left->p){
            t = rightRotate(t);
        }
    } else if(k > t->k){
        t->right = insert(t->right, k, p);
        if(t->p < t->right->p){
            t = leftRotate(t);
        }
    }
    return t;
}
Node *delete_(Node *t, int k);
Node *_delete(Node *t, int k){
    if(t->left == nullptr && t->right == nullptr){
        return nullptr;
    } else if(t->left == nullptr){
        t = leftRotate(t);
    } else if(t->right == nullptr){
	t = rightRotate(t);
    } else {
        if(t->left->p > t->right->p){
            t = rightRotate(t);
        } else {
            t = leftRotate(t);
        }
    }
    return delete_(t, k);
}

Node *delete_(Node *t, int k){
    if(t == nullptr){
        return nullptr;
    }
    if(k < t->k){
        t->left = delete_(t->left, k);
    } else if(k > t->k){
        t->right = delete_(t->right, k);
    } else {
        return _delete(t, k);
    }
    return t;
}
Node *find(Node *t, int k){
    if(t == nullptr){
        return nullptr;
    }
    if(k < t->k) return find(t->left, k);
    else if(k > t->k) return find(t->right, k);
    else return t;
}

void print_inorder(Node *t){
    if(t == nullptr) return;
    print_inorder(t->left);
    std::printf(" %d", t->k);
    print_inorder(t->right);
}

void print_preorder(Node *t){
    if(t == nullptr) return;
    std::printf(" %d", t->k);
    print_preorder(t->left);
    print_preorder(t->right);
}

int main(){
    int n;
    std::scanf("%d", &n);
    Node *root = nullptr;

    for(int i = 0; i < n; ++i){
	char op[8];
	std::scanf("%s", op);
	if(std::strncmp(op, "insert", 6) == 0){
            int k;
            std::scanf("%d", &k);
            int p;
            std::scanf("%d", &p);
            root = insert(root, k, p);
	} else if(std::strncmp(op, "delete", 6) == 0){
            int k;
            std::scanf("%d", &k);
            root = delete_(root, k);
	} else if(std::strncmp(op, "find", 4) == 0){
            int k;
            std::scanf("%d", &k);
            if(find(root, k) != nullptr){
		std::printf("yes\n");
            } else {
		std::printf("no\n");
            }
	} else if(std::strncmp(op, "print", 5) == 0){
            print_inorder(root);
            std::printf("\n");
            print_preorder(root);
            std::printf("\n");
	}
    }

    return 0;
}

