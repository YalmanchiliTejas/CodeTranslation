#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a-1][b-1] = adj[b-1][a-1] = 1;
    }
    vector<vector<int>> ans(1<<n, vector<int>(n, 0));
    ans[1][0] = 1;
    for(int state = 2; state < (1<<n); state++) {
        for(int i = 0; i < n; i++) {
            if ((state >> i) & 1) {
                int src = state ^ (1<<i);
                for(int j = 0; j < n; j++) {
                    if (((src >> j) & 1) && adj[j][i]) {
                        ans[state][i] += ans[src][j];
                    }
                }
            }
        }
    }
    int last = (1 << n) - 1;
    int ret = accumulate(ans[last].begin(), ans[last].end(), 0);
    cout << ret << endl;
    return 0;
}


