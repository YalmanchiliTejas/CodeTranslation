#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n+1, vector<int>(n+1, 0));
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int ans = 0;
    vector<int> p(n-1);
    iota(all(p), 2);
    while (true) {
        auto H = G;
        int now = 1;
        rep (i, p.size()) {
            if (H[now][p[i]] == 1) {
                H[now][p[i]] = H[p[i]][now] = 0;
                now = p[i];
            } else {
                break;
            }
            if (i == p.size() - 1) {
                ans++;
            }
        }
        if (!next_permutation(all(p))) {
            break;
        }
    }
    cout << ans << endl;
}


