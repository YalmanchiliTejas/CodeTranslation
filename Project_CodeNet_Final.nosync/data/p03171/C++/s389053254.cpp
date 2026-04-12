#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)     for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)     for(ll i = (a); i >= n; i--)
#define  fo(i,n)        for(ll i = 0; i < n; i++)
#define  all(x)         (x).begin(),(x).end()
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  newl           cout<<"\n"
#define  pb             push_back
#define  s              second
#define  f              first
#define  dline          cout<<"///REACHED///\n";
#define  deb1(x)        cout<<#x<<" = "<<x<<'\n';
#define  deb2(x,y)      cout<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define  deb3(x,y,z)    cout<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   MOD   =  1e+9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   MAXN  =  3e+3 + 8;

vll adj[MAXN]; ll visit[MAXN] = {};
int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

//<<-----Declare Variable Here------->>//
int t = 1;
ll n, a[MAXN];
ll dp[MAXN][MAXN][2];
//<<-----Implement Functions Here---->>//
ll solve(ll L, ll R, ll m) {
    if (L > R) return 0;

    if (dp[L][R][m] != -1) return dp[L][R][m];

    ll ans;
    if (m == 0) {
        ans = -INF;
        ans = max(ans, a[L] + solve(L + 1, R, 1));
        ans = max(ans, a[R] + solve(L, R - 1, 1));
    } else {
        ans = INF;
        ans = min(ans, solve(L + 1, R, 0));
        ans = min(ans, solve(L, R - 1, 0));
    }

    return dp[L][R][m] = ans;
}

//<<-----Start of Main--------------->>//
void MAIN() {
    mset(dp, -1);
    ll sum = 0;
    cin >> n;
    foo(i, 1, n)cin >> a[i], sum += a[i];
    cout << 2 * solve(1, n, 0) - sum;
}

int main() {
    fastio; randomINIT;

    //cin>>t;
    while (t--) {
        MAIN();
    }

}