#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;


template<class T>
class Treap{
private:
    struct Node{
        T val;
        int priority;
        Node* par;
        Node* left;
        Node* right;
        Node(){}
        Node(T val,int p):val(val),priority(p){}
    };
    Node *root;

    Node* rightRotate(Node* t){
        Node* s = t->left;
        t->left = s->right;
        s->right = t;
        return s;
    }

    Node* leftRotate(Node* t){
        Node* s = t->right;
        t->right = s->left;
        s->left = t;
        return s;
    }

    Node* insert(Node* t,T val,int priority){
        if(t == nullptr){
            t = new Node;
            t->left = nullptr;
            t->right = nullptr;
            t->val = val;
            t->priority = priority;
            return t;
        }
        /*
        if(val == t->val){
            return t;
        }
        */
        if(val < t->val){
            t->left = insert(t->left,val,priority);
            if(t->priority < t->left->priority){
                t = rightRotate(t);
            }
        }else{
            t->right = insert(t->right,val,priority);
            if(t->priority < t->right->priority){
                t = leftRotate(t);
            }
        }
        return t;
    }

    Node* erase(Node* t,T val){
        if(t == nullptr){
            return nullptr;
        }
        if(val < t->val){
            t->left = erase(t->left,val);
        }else if(val > t->val){
            t->right = erase(t->right,val);
        }else{
            return _erase(t,val);
        }
        return t;
    }

    Node* _erase(Node* t,T val){
        if(t->left == nullptr && t->right == nullptr){
            return nullptr;
        }else if(t->left == nullptr){
            t = leftRotate(t);
        }else if(t->right == nullptr){
            t = rightRotate(t);
        }else{
            if(t->left->priority > t->right->priority){
                t = rightRotate(t);
            }else{
                t = leftRotate(t);
            }
        }
        return erase(t,val);
    }

    bool find(Node* now,T x){
        if(now==nullptr) return false;
        if(now->val == x) return true;
        if(x < now->val){
            if(now->left != nullptr) return find(now->left,x);
        }else{
            if(now->right != nullptr) return find(now->right,x);
        }
        return false;
    }

    void inorder_walk(Node* now,vec<T>& v){
        if(now==nullptr) return ;
        if(now->left!=nullptr) inorder_walk(now->left,v);
        v.push_back(now->val);
        if(now->right!=nullptr) inorder_walk(now->right,v);
    }
    void preorder_walk(Node* now,vec<T>& v){
        if(now==nullptr) return ;
        v.push_back(now->val);
        if(now->left!=nullptr) preorder_walk(now->left,v);
        if(now->right!=nullptr) preorder_walk(now->right,v);
    }

public:
    Treap():root(nullptr){}
    
    void insert(T val,int priority){
        if(root == nullptr){
            root = new Node;
            root->left = nullptr;
            root->right = nullptr;
            root->val = val;
            root->priority = priority;
            return ;
        }
        root = insert(root,val,priority);
    }

    void erase(T val){
        root = erase(root,val);
    }

    bool find(T val){
        return find(root,val);
    }

    vec<T> inorder_walk(){
        if(root==nullptr) return {};
        vec<T> res;
        inorder_walk(root,res);
        return res;
    }
    vec<T> preorder_walk(){
        if(root==nullptr) return {};
        vec<T> res;
        preorder_walk(root,res);
        return res;
    }

};

int main(){
    int N;
    cin >> N;
    Treap<int> treap;
    for(int _=0;_<N;_++){
        string S;
        cin >> S;
        if(S=="print"){
            auto res = treap.inorder_walk();
            int n = res.size();
            for(int i=0;i<n;i++) cout << " " << res[i];
            cout << "\n";
            res = treap.preorder_walk();
            n = res.size();
            for(int i=0;i<n;i++) cout << " " << res[i];
            cout << "\n";
        }
        if(S=="insert"){
            int x,p;
            cin >> x >> p;
            treap.insert(x,p);
        }
        if(S=="find"){
            int x;
            cin >> x;
            cout << (treap.find(x)? "yes\n":"no\n");
        }
        if(S=="delete"){
            int x;
            cin >> x;
            treap.erase(x);
        }
    }
}
