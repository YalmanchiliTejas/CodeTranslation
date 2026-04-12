

#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;
typedef pair<ll, ll> pint;


void yesno(bool b) {
    if (b) {
        cout << "Yes" << endl;
    }     else {
        cout << "No" << endl;
    }

}

const ll INF = 1e18;
ll dp[200005][4];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int k = 1 + n%2;
    rep(i, n+1) rep(j, k+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, k+1) {
            chmax(dp[i+1][j+1], dp[i][j]);
            ll now = dp[i][j];
            if ((i+j) % 2 == 0) now += a[i];
            chmax(dp[i+1][j], now);
        }
    }

    ll ans = dp[n][k];
    cout << ans << endl;

}