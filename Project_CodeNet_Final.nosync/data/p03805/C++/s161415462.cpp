#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int N;
int walk(const vector<vector<bool>>& V, int cur, set<int> done) {
    if (done.size() == N) return 1;
    int res = 0;
    rep(i, N) {
        if (done.count(i) == 0 && V[cur][i]) {
            set<int> d2 = done;
            d2.insert(i);
            res += walk(V, i, d2);
        }
    }
    return res;
}

int main() {
    int M; cin >> N >> M;
    vector<vector<bool>> V(N, vector<bool>(N,false));

    rep(i, M) {
        int a, b; cin >> a >> b;
        V[a - 1][b - 1] = true;
        V[b - 1][a - 1] = true;
    }
    set<int> done = {0};
    cout << walk(V, 0, done) << endl;
}
