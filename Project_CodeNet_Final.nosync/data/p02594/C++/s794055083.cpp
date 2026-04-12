///#pragma GCC optimize("O3,unroll-loops")
///#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ull unsigned long long
#define ld long double
#define inf 2000000000
#define infLL 2000000000000000000
#define MAX5 100005
#define MAX6 1000006
#define MAX7 10000007
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define pf(a) printf("%d\n", a)
#define pfl(a) printf("%lld\n", a)
#define pfs(a) printf("%s\n", a)
#define Case(t) printf("Case #%d: ", t)
#define pii pair<int, int>
#define mod 1000000007
#define Mod 998244353
#define PI acos(-1.0)
#define eps 1e-9
#define mem(a, b) memset(a, b, sizeof(a))
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }

inline int Set(ll N, ll pos){return N=N | (1LL<<pos);}
inline int Reset(ll N, ll pos){return N=N & ~(1LL<<pos);}
inline bool Check(ll N, ll pos){return (bool)(N & (1LL<<pos));}

inline bool Equal(ld x, ld y) { return fabs(x-y) < eps; } ///x==y
inline bool Greater(ld x, ld y) { return (x - eps) > y; } /// x>y
inline bool Lesser(ld x, ld y) { return (x + eps) < y; }  /// x<y

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

/// Memory Efficient
inline ll fast_exp(ll x, ll n, ll m) { ll res = 1; while(n>0) { if(n%2==1) res = (res * x) % m; x = (x * x) % m; n/=2; } return res%m; }

// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

inline void Time() { cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"; }

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>orderedSet1;

const int N = MAX6;

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    FASTIO;
    int x;
    cin>>x;
    if(x >= 30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    ///Time();
    return 0;
}
