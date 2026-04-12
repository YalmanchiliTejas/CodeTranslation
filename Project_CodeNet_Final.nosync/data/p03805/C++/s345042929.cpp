#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int n,m; cin >> n >> m;
    int G[n][n];
    rep(i,n)rep(j,n) G[i][j] = 0;
    int u,v;
    rep(i,m) {
        cin >> u >> v;
        u--; v--;
        G[u][v] = G[v][u] = 1;
    }

    int ans = 0;
    vector<int> a(n-1);
    rep(i,n-1) a[i] = i+1;

    do {
        bool check = true;
        rep(i,n-1) {
            if (i==0) {
                if (G[0][a[0]] != 1) {
                    check = false;
                    break;
                }
            }
            else if (G[a[i-1]][a[i]] != 1) {
                check = false;
                break;
            }
        }
        if (check) ans++;
    } while (next_permutation(all(a)));

    cout << ans << endl;
}