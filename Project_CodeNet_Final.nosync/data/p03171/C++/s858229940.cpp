#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define pb(x)                       push_back(x)
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const int MAXN = 3e3 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;
ll a[MAXN];
ll dp[MAXN][MAXN];
ll n;

bool check(ll k){
    if ((n % 2 and k % 2) or (!n%2 and !k%2)){
        return true;
    }
    return false;
}

ll memoize(int l,int r){
    if (l > r){
        return 0;
    }
    if (dp[l][r] != -1){
        return dp[l][r];
    }
    int turn = n - r + l;
    if (turn & 1){
        return dp[l][r] = max(memoize(l + 1,r) + a[l],memoize(l,r - 1) + a[r]);
    }
    else{
        return dp[l][r] = min(memoize(l + 1,r) - a[l],memoize(l,r - 1) - a[r]);
    }
}

int main()
{
    fast_io;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cout << memoize(1,n) << endl;
}
