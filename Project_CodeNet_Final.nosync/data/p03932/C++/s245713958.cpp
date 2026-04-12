#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(_v) for(auto _x:_v){cout<<_x<<" ";}cout<<endl
#define printVS(_vs) for(auto _x : _vs){cout << _x << endl;}
#define printVV(_vv) for(auto _v:_vv){for(auto _x:_v){cout<<_x<<" ";}cout<<endl;} cout << endl;
#define printP(_p) cout << _p.first << " " << _p.second << endl
#define printVP(_vp) for(auto _p : _vp) printP(_p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
const int inf = 1e9;
const int mod = 1e9 + 7;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int H, W;
    cin >> H >> W;
    int N = max(H, W);
    vvi a(N + 1, vi(N + 1));
    rep(i, N) rep(j, N) cin >> a[i + 1][j + 1];

    vvi b(2 * N + 1, vi(N + 1));
    rep(i, N + 1) {
        rep(j, N + 1) {
            b[i + j][j] = a[i][j];
        }
    }

    vvvi dp(2 * N + 1, vvi(N + 1, vi(N + 1)));
    rep2(i, 1, 2 * N + 1) {
        rep2(j, 1, N + 1) {
            rep2(k, 1, N + 1) {
                dp[i][j][k] = max({dp[i-1][j][k],
                                    dp[i-1][j][k-1],
                                    dp[i-1][j-1][k],
                                    dp[i-1][j-1][k-1]});
                dp[i][j][k] += (j != k ? b[i][j] + b[i][k] : b[i][j]);
            }
        }
    }
    cout << dp.back().back().back() << endl;
}
