#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
using namespace std;

int N, M, a, b, ret; vector<int> G[11];
void solve(int pos, int bit) {
    if (bit == (1 << N) - 1) {
        ret++;
        return;
    }
    for (int i : G[pos]) {
        if (!(bit & (1 << i))) {
            solve(i, bit + (1 << i));
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve(0, 1);
    cout << ret << endl;
    return 0;
}