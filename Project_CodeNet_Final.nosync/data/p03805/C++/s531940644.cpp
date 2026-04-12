/*
ID: y1197771
PROG: test
LANG: C++
*/
#include<bits/stdc++.h>
#define pb push_back
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
#define dbg(x) cout << #x << " at line " << __LINE__ << " is: " << x << endl
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e3 + 10;
int n, m;
int e[10][10];
void solve() {
    cin >> n >> m;
    vector<int> v;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        e[x][y] = e[y][x] = 1;
    }
    for (int i = 2; i <= n; i++) {
        v.pb(i);
    }
    int res = 0;
    do {
        bool f = 0;
        if(e[1][v[0] ]) {
            f = 1;
            for (int i = 1; i < v.size(); i++) {
                if(!e[v[i - 1] ][v[i] ]) {
                    f = 0; break;
                }
            }
        }
        if(f) res++;
    } while(next_permutation(v.begin(), v.end()));
    cout << res << endl;
}
int main() {
  //  freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
