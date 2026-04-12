#include <bits/stdc++.h>
using namespace std;

typedef struct node node_t;
typedef struct node{
    int16_t id;
    int16_t visited;
    int nextcnt;
    node_t *next[8];
} node_t;

int test(node_t * vertex, int nodeid, int visitcnt, int from);
int N,M;

int main(void) {
    int tmp;
    node_t *vertex;
    int a,b;
    int sum;

    cin >> N >> M;

    vertex = (node_t*)calloc(1, sizeof(node_t) * 8);
    for(int i=0;i<8;i++) {
        vertex[i].id = i;
    }

    for(int i=0;i<M;i++) {
        cin >> a >> b;
        vertex[a-1].next[vertex[a-1].nextcnt++] = &vertex[b-1];
        vertex[b-1].next[vertex[b-1].nextcnt++] = &vertex[a-1];
    }


    vertex[0].visited = 1;
    sum = test(vertex, 0, 1, -1);
    cout << sum << "\n";
    free(vertex);

    return 0;
}

int test(node_t * vertex, int nodeid, int visitcnt, int from) {
    int sum = 0;

// printf("debug %d->%d(%d)\n", from,nodeid, visitcnt);

    if((N - visitcnt) == 0) {
        sum = 1;
        return sum;
    }

    // 最初は必ず1から
    for(int i=0;i<vertex[nodeid].nextcnt;i++) {
        if(vertex[vertex[nodeid].next[i]->id].visited == 1){
            continue;
        }
        vertex[vertex[nodeid].next[i]->id].visited = 1;
        sum += test(vertex, vertex[nodeid].next[i]->id, visitcnt + 1, nodeid);
        vertex[vertex[nodeid].next[i]->id].visited = 0;
    }

    return sum;
}
