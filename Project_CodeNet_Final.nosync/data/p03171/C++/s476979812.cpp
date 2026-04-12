#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e15;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 1e5 + 100;
const int LOG = 20;
const int mod = 1e9 + 7;
const int MX = 1e6 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;

ll dp[3100][3100];
int a[3100];

ll get(int l, int r, int step) {
    if (dp[l][r] != -1)
        return dp[l][r];
    ll &res = dp[l][r];
    if(l==r){
        if(step==0){
            res = a[l];
        } else{
            res = -a[l];
        }
        return res;
    }
    if (step == 0) {
        res = -inf_ll;
        res = max(res, get(l + 1, r, step ^ 1) + a[l]);
        res = max(res, get(l, r - 1, step ^ 1) + a[r]);
    } else {
        res = inf_ll;
        res = min(res, get(l+1,r, step^1) - a[l]);
        res = min(res, get(l,r-1,step^1) - a[r]);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    memset(dp,-1,sizeof dp);

    cout << get(1,n,0)<<"\n";
}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
#else

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;

    while (t--)
        solve();
    dout << endl << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}