//
// Created by tattsun on 2017/02/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define NODE_MAX 8
#define EDGE_MAX 28
#define NIL -1

using namespace std;

struct Edge {
    Edge(): a(NIL), b(NIL) {
    }
    int a;
    int b;

    int destination(int from) {
        if(a == from) return b;
        else if(b == from) return a;
        else {
            cout << "err: destination" << endl;
            exit(1);
        }
    }

    bool is_nil() {
        return a == NIL && b == NIL;
    }
};

int n, m;
vector<Edge*> ns[NODE_MAX];
Edge es[EDGE_MAX];

int visit(int node, vector<int> visited) {
    visited.push_back(node);

    if(visited.size() == n) return 1;

    int paths = 0;
    for(int i=0; i<ns[node].size(); i++) {
        int dest = ns[node][i]->destination(node);
        if(find(visited.begin(), visited.end(), dest) != visited.end()) {
            continue;
        }

        paths += visit(dest, visited);
    }

    return paths;
}

int solve() {
    return visit(0, vector<int>());
};

int main() {
    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        a -= 1;
        b -= 1;
        es[i].a = a;
        es[i].b = b;
        ns[a].push_back(&es[i]);
        ns[b].push_back(&es[i]);
    }

    cout << solve() << endl;
}