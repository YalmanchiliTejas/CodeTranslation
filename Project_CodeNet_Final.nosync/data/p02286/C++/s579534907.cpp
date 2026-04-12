#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<set>
#include<cstring>
#include<string>
#include<stack>
#include<stdlib.h>
#include<math.h>
using namespace std;
//#define int long long
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef priority_queue<pii, vector<pii>, greater<pii> > RPQ;
#define mk make_pair
#define INF (1 << 30)
#define INFL (1ll << 60ll)
#define mod 1000000007
typedef struct node * nodept;

struct node{
    int key = -1;
    int priority = -1;
    node *right;
    node *left;
};

nodept nil, root;

void init(){
    nil = (nodept)malloc(sizeof(node));
    nil->left = nil;
    nil->right = nil;

    root = nil;
}

nodept gennode(int key, int priority, nodept left = nil, nodept right = nil){
    nodept t = (nodept)malloc(sizeof(node));
    *t = {key, priority, left, right};
    return t;
}

nodept rightRotate(nodept t){
    nodept s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

nodept leftRotate(nodept t){
    nodept s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

nodept insert(nodept t, int key, int priority){
    if(t == nil){
        return gennode(key, priority);
    }
    if(key == t->key)return t;

    if(key < t->key){
        t->left = insert(t->left, key, priority);
        if(t->priority < t->left->priority){
            t = rightRotate(t);
        }
    }
    else {
        t->right = insert(t->right, key, priority);
        if(t->priority < t->right->priority){
            t = leftRotate(t);
        }
    }
    return t;
}

nodept _Delete(nodept t, int key);

nodept Delete(nodept t, int key){
    if(t == nil){
        return nil;
    }
    if(key < t->key){
        t->left = Delete(t->left, key);
    }
    else if(key > t->key){
        t->right = Delete(t->right, key);
    }
    else {
        return _Delete(t, key);
    }
    return t;
}

nodept _Delete(nodept t, int key){
    if(t->left == nil && t->right == nil){
        return nil;
    }
    else if(t->left == nil){
        t = leftRotate(t);
    }
    else if(t->right == nil){
        t = rightRotate(t);
    }
    else {
        if(t->left->priority > t->right->priority){
            t = rightRotate(t);
        }
        else {
            t = leftRotate(t);
        }
    }
    return Delete(t, key);
}

nodept find(nodept t, int key){
    if(t == nil)return nil;
    if(key < t->key){
        return find(t->left, key);
    }
    else if(key > t->key){
        return find(t->right, key);
    }
    else {
        return t;
    }
}

void indfs(nodept t){
    if(t == nil)return;
    indfs(t->left);
    printf(" %d", t->key);
    indfs(t->right);
}

void predfs(nodept t){
    if(t == nil)return;
    printf(" %d", t->key);
    predfs(t->left);
    predfs(t->right);
}

signed main(){
    int M;
    cin >> M;
    init();
    for(int i = 0; i < M; i++){
        char query[10];
        cin >> query;
        int key;
        if(query[0] == 'i'){
            int priority;
            cin >> key >> priority;
            root = insert(root, key, priority);
        }
        else if(query[0] == 'f'){
            cin >> key;
            if(find(root, key) != nil){
                printf("yes\n");
            }
            else printf("no\n");
        }
        else if(query[0] == 'd'){
            cin >> key;
            root = Delete(root, key);
        }
        else {
            indfs(root);
            printf("\n");
            predfs(root);
            printf("\n");
        }
    }


    return 0;
}

/*



*/
