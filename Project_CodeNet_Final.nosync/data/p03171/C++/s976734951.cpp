#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

ll dp[3005][3005];

int main() {
    int n; cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) dp[i][i] = a[i];
    for (int len = 1; len < n; len++) {
        for (int l = 0; l < n-len; l++) {
            int r = l + len;
            dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    cout << dp[0][n-1] << endl;
}