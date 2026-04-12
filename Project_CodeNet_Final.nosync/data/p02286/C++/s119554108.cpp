#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;

#define BIG_NUM 200000000
#define HUGE_NUM 999999999999
#define MOD 100000007
#define EPS 0.0000000001
using namespace std;

#define SIZE 200005

struct Node {
    int key, priority;
    int left, right;
};

int num_nodes, root;
Node nodes[SIZE];

int leftRotate(int node_id) {
    //node_id番のノードの右側の子valueをretに代入
    int ret = nodes[node_id].right;
    
    //ret番のノードの左側の子valueを右側の子のノードに代入
    nodes[node_id].right = nodes[ret].left;
    nodes[ret].left = node_id;
    
    return ret;
}

int rightRotate(int node_id) {
    int ret = nodes[node_id].left;
    nodes[node_id].left = nodes[ret].right;
    nodes[ret].right = node_id;
    
    return ret;
}

int insert(int node_id, int key, int priority) {
    if(node_id == -1) {
        //葉に到達したら新しい節点を生成して返す
        nodes[num_nodes].key      = key;
        nodes[num_nodes].priority = priority;
        nodes[num_nodes].left     = -1;
        nodes[num_nodes].right    = -1;
        
        num_nodes++;
        return num_nodes - 1;
    }
    
    if(nodes[node_id].key == key) {
        //重複したkeyは無視
        return node_id;
    }
    
    if(nodes[node_id].key > key) {
        //左の子のポインタを更新
        nodes[node_id].left = insert(nodes[node_id].left, key, priority);
        
        if(nodes[node_id].priority < nodes[nodes[node_id].left].priority) {
           //左の子の方がpriority値が高いなら右回転
            node_id = rightRotate(node_id);
        }
    }else {
        nodes[node_id].right = insert(nodes[node_id].right, key, priority);
        if(nodes[node_id].priority < nodes[nodes[node_id].right].priority) {
            node_id = leftRotate(node_id);
        }
    }
    return node_id;
}

int DELETE(int node_id, int key);

int DELETE_2(int node_id, int key) {
    //削除対象の節点の場合・・・
    
    if(nodes[node_id].left == -1 && nodes[node_id].right == -1) {
        //葉のとき
        return -1;
    }else if(nodes[node_id].left == -1) {
        //右の子のみを持つ場合は左回転
        node_id = leftRotate(node_id);
    }else if(nodes[node_id].right == -1) {
        //左の子のみを持つ場合は右回転
        node_id = rightRotate(node_id);
    }else {
        //左右の子を持つときはpriorityが高い方を引き上げる
        if(nodes[nodes[node_id].left].priority > nodes[nodes[node_id].right].priority) {
            node_id = rightRotate(node_id);
        }else {
            node_id = leftRotate(node_id);
        }
    }
    return DELETE(node_id, key);
}

int DELETE(int node_id, int key) {
    if(num_nodes == 0 || node_id == -1) {
        return -1;
    }
    //削除対象を検索
    if(nodes[node_id].key > key) {
        nodes[node_id].left = DELETE(nodes[node_id].left, key);
    }else if(nodes[node_id].key < key) {
        nodes[node_id].right = DELETE(nodes[node_id].right, key);
    }else {
        return DELETE_2(node_id, key);
    }
    
    return node_id;
}

void find(int key) {
    if(num_nodes == 0) {
        printf("no\n");
        return;
    }
    
    int current_node = root;
    
    while(true) {
        if(nodes[current_node].key == key) {
            printf("yes\n");
            return;
        }else if(nodes[current_node].key > key) {
            current_node = nodes[current_node].left;
        }else {
            current_node = nodes[current_node].right;
        }
        
        if(current_node == -1) {
            printf("no\n");
            return;
        }
    }
}

void in_order(int node_id) {
    if(node_id == -1) return;
    
    if(nodes[node_id].left != -1) {
        in_order(nodes[node_id].left);
    }
    
    printf(" %d", nodes[node_id].key);
    
    if(nodes[node_id].right != -1) {
        in_order(nodes[node_id].right);
    }
}

void pre_order(int node_id) {
    if(node_id == -1) return;
    
    printf(" %d", nodes[node_id].key);
    if(nodes[node_id].left != -1) {
        pre_order(nodes[node_id].left);
    }
    if(nodes[node_id].right != -1) {
        pre_order(nodes[node_id].right);
    }
}

int main() {
    num_nodes = 0;
    
    int M;
    scanf("%d", &M);
    
    char command[10];
    int key, priority;
    
    root = -1;
    
    for(int loop = 0; loop < M; loop++) {
        scanf("%s", command);
        
        switch(command[0]) {
            case 'i':
                scanf("%d %d", &key, &priority);
                root = insert(root, key, priority);
                break;
            
            case 'f':
                scanf("%d", &key);
                find(key);
                break;
                
            case 'd':
                scanf("%d", &key);
                root = DELETE(root, key);
                break;
            
            case 'p':
            if(num_nodes == 0) break;
            
            in_order(root);
            printf("\n");
            pre_order(root);
            printf("\n");
            
            break;
        }
    }
    return 0;
}
