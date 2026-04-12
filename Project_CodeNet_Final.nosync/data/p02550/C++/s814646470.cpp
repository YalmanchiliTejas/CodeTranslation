#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
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

const ll mod = 998244353;
const ll inf = (ll)1e16;
const ld eps = 1e-12;
const ll N = (int)1e6 + 5;
const ll LOGN = 19;
const ld PI = 3.14159265358979323846;
inline ll mul(ll a, ll b, ll m = mod) { return (ll)(a * b) % m;}
inline ll add(ll a, ll b, ll m = mod) { a += b; if(a >= m) a -= m; if(a < 0) a += m; return a;}
inline ll power(ll a, ll b, ll m = mod) { if(b == 0) return 1; if(b == 1) return (a % m); ll x = power(a, b / 2, m); x = mul(x, x, m); if(b % 2) x = mul(x, a, m); return x;}

map<int, int> mp;
int a[N];

void solve() {
    int n, x, m;
    cin>>n>>x>>m;
    a[0] = x;
    mp[x] = 0;
    int ind = 1;
    bool cycle = false;
    int st = 0;
    while(ind < n) {
        int curr = mul(a[ind - 1], a[ind - 1], m);
        if(mp.find(curr) != mp.end()) {
            cycle = true;
            st = mp[curr];
            break;
        }
        else {
            mp[curr] = ind;
            a[ind++] = curr;
        }
    }
    int ans = 0;
    f(i, ind) ans += a[i];
    if(!cycle) {
        cout<<ans<<endl;
        return;
    }
    int cycSum = 0, cycLen = 0;
    for(int i = st; i < ind; i++) {
        cycLen++;
        cycSum += a[i];
    }
    int rem = n - ind;
    int num = rem / cycLen;
    ans += num * cycSum;
    rem %= cycLen;
    for(int i = st; i < ind; i++) {
        if(rem == 0) break;
        ans += a[i];
        rem--;
    }
    cout<<ans<<endl;
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
    for(int test = 1; test <= t; test++) {
        //cout<<"Case #"<<test<<": ";
        solve();
    }
    return 0;
}