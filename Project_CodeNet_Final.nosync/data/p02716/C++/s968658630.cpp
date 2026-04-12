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
#define bitcount __builtin_popcount
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
typedef double  db ;
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
const int N = 2e5+5;
int n;
int dp[N][4][2][3][2], arr[N];
inline int solve(int id, int c, int c1, int c2, int f) {
    if(id == n) {
        if(c == 2) c2++;
        if(c == 3) c1++;
        if(f) {
            ret c1 == 1 || c2 > 0 ? 0 : -inf;
        } 
        ret 0;
    }
    if(dp[id][c][c1][c2][f] != -1) ret dp[id][c][c1][c2][f];
    int ans = -inf;
    if(c == 0) {
        ans = max(ans, solve(id + 1, 1, c1, c2, f));
    } else if(c == 1) {
        ans = max(ans, arr[id] + solve(id + 1, 0, c1, c2, f));
        if(c1 == 0 and c2 < 2) {
            ans = max(ans, solve(id + 1, 2, c1, c2, f));
        }
    } else if(c == 2) {
        ans = max(ans, arr[id] + solve(id + 1, 0, c1, c2 + 1, f));
        if(c1 == 0 and c2 == 0 and f) {
            ans = max(ans, solve(id + 1, 3, c1, c2, f));
        }
    } else {
        ans = max(ans, arr[id] + solve(id + 1, 0, c1 + 1, c2, f));
    }
    ret dp[id][c][c1][c2][f] = ans;
}
inline void solve_me_senpai() {
    cin >> n;
    rep(i, n) cin >> arr[i];
    mem(dp, -1);
    int ans = -inf;
    if(n & 1) {
        ans = max({solve(1, 0, 0, 0, 1) + arr[0], solve(2, 0, 0, 1, 0) + arr[1], solve(3, 0, 0, 2, 0) + arr[2]});
    } else {
        ans = max({solve(1, 0, 0, 1, 0) + arr[0], solve(2, 0, 0, 2, 0) + arr[1]});
    }
    o(ans);
}
int32_t main()
{
    boost
    int t = 1;
    //cin >> t;
    int a = 1;
    while(t--) {
        //cout << "Case #" << a  << ": ";
        solve_me_senpai();
        a++;
    }
    //skj();
    return 0;
}