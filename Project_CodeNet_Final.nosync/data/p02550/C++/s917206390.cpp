#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define emp emplace
#define ins insert
#define mp make_pair
#define mt make_tuple
#define sz(s) (int)s.size()
#define forp(i,a,b) for( int i=a;i<=b;i++)
#define rep(i,n)    for( int i=0;i<n;i++)
#define ren(i,n)    for( int i=n-1;i>=0;i--)
#define forn(i,a,b) for( int i=a;i>=b;i--)
#define w(t) while(t)
#define sc(a) scanf("%d", &a);
#define on cout<<"\n"
#define os cout <<" "
#define o2(a,b) cout<<a<<" "<<b
#define o(a) cout << a
#define ppr(a) cout << a.first << " " << a.second
#define bitcount __builtin_popcountll
#define gcd __gcd
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define mem(n,m) memset(n,m,sizeof(n))
#define pii pair<int,int>
#define tiii tuple<int, int, int>
#define pll pair<long long,long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int>
#define vll vector<long long>
#define mii map<int,int>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define ret return
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define ford(container, it) for(auto it = container.begin(); it != container.end(); it++)
#define fors(container, it, a, b) for(auto it = a; it != b; it++)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD   998244353
#define EPSILON 1e-9
#define PI acos(-1)
#define int long long
#define inf 1e16
#define debug(a) cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define trace(a) cerr<<#a<<": "<<a<<"\n"
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


typedef long long  ll;
typedef long double  ldo;
//typedef double  db ;
using namespace std;
auto start = std::chrono::system_clock::now();
inline void skj()
{
std::chrono::time_point<std::chrono::system_clock> end;
end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end - start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
cerr<<"Time taken " << elapsed_seconds.count()*1000<<"\n";
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int> ud(1, 100); use this for random number generator
int csrand(int l=0, int r=1e9){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
    //custom hash for unordered map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
inline int binexp(int a,int b,int m)
{
    if(a == 0) {
        ret 0;
    }
    int res=1;
    a%=m;
    while(b)
    {
        if(b&1)
            res=(res*1ll*a)%m;
        a=(a*1ll*a)%m;
        b>>=1;
    }
    return res;
}
inline int binmul(int a, int b, int m) {
    a %= m;
    int res = 0;
    w(b) {
        if(b & 1) {
            res = (res + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    ret res;
}
void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    vii arr;
    unordered_map<int, int, custom_hash> M;
    while(M.find(x) == M.end()) {
        M[x] = sz(arr);
        arr.pb(x);
  //      cout << x << "\n";
        x = (x * x) % m;
    }
    vii repeat;
    int sm = 0;
    for(int i = M[x]; i < sz(arr); ++i) {
        repeat.pb(arr[i]);
        sm += arr[i];
    }
    int ans = 0;
    for(int i = 0; i < min(n, sz(arr)); ++i) {
        ans += arr[i];
    }
    if(n <= sz(arr)) {
        cout << ans << "\n";
        ret;
    }
    n -= sz(arr);
    ans += sm * (n / sz(repeat));
    for(int i = 0; i < n % sz(repeat); ++i) {
        ans += repeat[i];
    }
    cout << ans;
}
int32_t main()
{
    boost
    int t = 1;
    //cin >> t;
    int a = 1;
    while(t--) {
        //cout << "Case #" << a  << ": ";
        solve();
        a++;
    }
    //skj();
    return 0;
}