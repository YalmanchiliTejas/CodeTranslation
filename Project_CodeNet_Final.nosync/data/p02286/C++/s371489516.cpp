#include <iostream>
#include <string>

using namespace std;

#define ORDER_MAX 200000
#define DATA_MAX 2000000000

class Treap{
    struct Node{
        int key;
        int value;
        Node *left;
        Node *right;
        
        Node(){
            key = 0;
            value = 0;
            left = NULL;
            right = NULL;
        }
        
        Node(int k, int v){
            key = k;
            value = v;
            left = NULL;
            right = NULL;
        }
        
        ~Node(){
            key = -1;
            value = -1;
            left = NULL;
            right = NULL;
        }
    };
    
private:
    Node *tree;
    
    Node* insert(Node *target, int key, int value){
        if(target == NULL)
            return new Node(key, value);
        if(key == target->key)
            return target;
        
        if(key < target->key){
            target->left = insert(target->left, key, value);
            if(target->value < target->left->value)
                target = Righting(target);
        }
        else{
            target->right = insert(target->right, key, value);
            if(target->value < target->right->value)
                target = Lefting(target);
        }
        
        return target;
    }
    
    Node* Lefting(Node *target){
        Node *tmp = target->right;
        target->right = tmp->left;
        tmp->left = target;
        return tmp;
    }
    
    Node* Righting(Node *target){
        Node *tmp = target->left;
        target->left = tmp->right;
        tmp->right = target;
        return tmp;
    }
    
    
    
    void in_order(Node *n){
        if(n == NULL)
            return;
        
        in_order(n->left);
        cout << " " << n->key;
        in_order(n->right);
    }
    
    void pre_order(Node *n){
        if(n == NULL)
            return;
        
        cout << " " << n->key;
        pre_order(n->left);
        pre_order(n->right);
    }
    
    Node* erase(Node *target, int key){
        if(target == NULL)
            return NULL;
        
        if(key == target->key){
            if(target->right == NULL && target->left == NULL){
                delete target;
                return NULL;
            }
            else if(target->left == NULL)
                target = Lefting(target);
            else if(target->right == NULL)
                target = Righting(target);
            else
                target = target->left->value > target->right->value ? Righting(target) : Lefting(target);
        }
        
        if(key < target->key)
            target->left = erase(target->left, key);
        else
            target->right = erase(target->right, key);
        
        return target;
    }
    
public:
    Treap(){
        tree = NULL;
    }
    
    Node* find(int k){
        for(Node *target = tree; target != NULL; target = k < target->key ? target->left : target->right)
            if(k == target->key)
                return target;
        
        return NULL;
    }
    
    void insert(int k, int v){
        tree = insert(tree, k, v);
    }
    
    void erase(int k){
        tree = erase(tree, k);
    }
    
    void print(){
        in_order(tree);
        cout << endl;
        pre_order(tree);
        cout << endl;
    }
};

int main(){
    Treap th;
    int n;
    string op;
    int k ,v;
    
    cin >> n;
    if(!(0 <= n && n <= ORDER_MAX))
        return -1;
    
    for(int i = 0; i < n; i++){
        cin >> op;
        if(op == "print")
            th.print();
        else if(op == "insert"){
            cin >> k >> v;
            if(!(0 <= k && k <= DATA_MAX) || !(0 <= v && v <= DATA_MAX))
                return -1;
            th.insert(k, v);
        }
        else if(op == "find"){
            cin >> k;
            if(!(0 <= k && k <= DATA_MAX))
                return -1;
            cout << (th.find(k) == NULL ? "no" : "yes") << endl;
        }
        else if(op == "delete"){
            cin >> k;
            if(!(0 <= k && k <= DATA_MAX))
                return -1;
            th.erase(k);
        }
        else
            return -1;
    }
    
    return 0;
}

