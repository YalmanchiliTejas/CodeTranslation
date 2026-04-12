#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> edge;

vector<int> ts;

void dfs(int par, int now) {
    ts.push_back(now);
    for (int nxt : edge[now]) {
        if (nxt != par) dfs(now, nxt);
    }
    return;
}

int main() {
    int N;
    cin >> N;
    edge.resize(N+1);
    
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(0, 1);
    
    if (N%2 == 1) {
        cout << "First\n";
        return 0;
    }
    
    vector<int> match(N+1, 0);
    for (int i = N-1; i >= 0; i--) {
        int a = 0, b = 0;
        for (int child : edge[ts[i]]) {
            if (match[child] == 1) a++;
            if (match[child] == 2) b++;
        }
        if (b == 0) {
            match[ts[i]] = 2;
        }else if (b == 1) {
            match[ts[i]] = 1;
        }else {
            cout << "First\n";
            return 0;
        }
    }
    cout << "Second\n";
    return 0;
}