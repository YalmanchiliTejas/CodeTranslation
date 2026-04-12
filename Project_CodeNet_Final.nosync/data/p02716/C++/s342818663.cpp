#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pl;
typedef pair<int,int> pii;

#define int ll
#define LOCAL 0
#define dbg(x) cout << #x << " is " << x << "\n"
#define gll(x) scanf("%d",&x)
#define gll2(x,y) scanf("%d%d",&x,&y)
#define gll3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gllarr(arr,n) f(i,n) gll(arr[i]);
#define sz(x) ((int)x.size())
#define s(x) sort(x.begin(),x.end())
#define all(v) v.begin(),v.end()
#define rs(v) { s(v) ; r(v) ; }
#define r(v) {reverse(all(v));}
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)

const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e16;
const ld eps = 1e-12;
const ll N = (int)2e5 + 5;
const ll LOGN = 19;
const ld PI = 3.14159265358979323846;
inline ll mul(ll a, ll b, ll m = mod) { return (ll)(a * b) % m;}
inline ll add(ll a, ll b, ll m = mod) { a += b; if(a >= m) a -= m; if(a < 0) a += m; return a;}
inline ll power(ll a, ll b, ll m = mod) { if(b == 0) return 1; if(b == 1) return (a % m); ll x = power(a, b / 2, m); x = mul(x, x, m); if(b % 2) x = mul(x, a, m); return x;}

int n;
int a[N];
int odd_sum[N], even_sum[N];
int dp[N][2][2];

int rec(int pos, bool odd, bool taken) {
    if(pos >= n) return 0;
    if(pos == n - 1) {
        if(!taken) return 0;
        else return a[pos];
    }
    int &ans = dp[pos][odd][taken];
    if(ans != -1) return ans;
    ans = LLONG_MIN;
    if(!taken) {
        int id = 1;
        if((pos + 1) / 2 == pos / 2) id = 2;
        ans = rec(pos + id, false, true);

        ans = max(ans, rec(pos + 2, odd, false) + a[pos]);
        if(pos + 3 < n && !odd) ans = max(ans, rec(pos + 3, true, false) + a[pos]);
    }
    else  {
        ans = max(ans, rec(pos + 2, false, true) + a[pos]);
    }
    return ans;
}

void solve() {
    cin>>n;
    f(i, n) cin>>a[i];
    even_sum[0] = a[0];
    for(int i = 1; i < n; i++) {
        even_sum[i] = even_sum[i - 1];
        if(i & 1) continue;
        even_sum[i] += a[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i != n - 1) odd_sum[i] = odd_sum[i + 1];
        if(i & 1) {
            odd_sum[i] += a[i];
        }
    }
    f(i, n) {
        f(j, 2) f(k, 2) dp[i][j][k] = -1;
    }
    int ans;
    if(n % 2 == 0) {
        ans = odd_sum[0];
        for(int i = 0; i < n / 2; i++) {
            int id = 2 * i;
            int cans = even_sum[id] + (id + 2 < n) * odd_sum[id + 2];
            ans = max(ans, cans);
        }
        cout<<ans;
    }
    else {
        cout<<max(rec(0, 0, 0), rec(1, 1, 0));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (LOCAL) {
        freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\input.txt", "r", stdin);
        freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\output.txt", "w", stdout);
    }
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
