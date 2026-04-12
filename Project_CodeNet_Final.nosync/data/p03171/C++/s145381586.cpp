#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

const int MAX_N = 3010;
int n;
ll a[MAX_N];

ll dp[MAX_N][MAX_N][2];
bool used[MAX_N][MAX_N][2];

ll calcSecond(int l, int r);

ll calcFirst(int l, int r) {
    if (used[l][r][0]) return dp[l][r][0];
    used[l][r][0] = true;
    auto& ret = dp[l][r][0];
    ret = -1e18;
    if(r - l == 1) ret = a[l];
    else {
        chmax(ret, a[l] + calcSecond(l+1, r));
        chmax(ret, a[r-1] + calcSecond(l, r-1));
    }
    return ret;
}
ll calcSecond(int l, int r) {
    if (used[l][r][1]) return dp[l][r][1];
    used[l][r][1] = true;
    auto& ret = dp[l][r][1];
    ret = 1e18;
    if(r - l == 1) ret = -a[l];
    else {
        chmin(ret, -a[l] + calcFirst(l+1, r));
        chmin(ret, -a[r-1] + calcFirst(l, r-1));
    }
    return ret;
}

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    cout << calcFirst(0, n) << endl;
    // rep(i, n+1) {
    //     rep(j, n+1) printf("%4lld", dp[i][j][0]);
    //     cout << endl;
    // }
    // cout << endl;
    // rep(i, n+1) {
    //     rep(j, n+1) printf("%4lld", dp[i][j][1]);
    //     cout << endl;
    // }
    return 0;
}