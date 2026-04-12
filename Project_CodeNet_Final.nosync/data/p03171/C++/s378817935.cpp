/*
Author: Qaseem Hasan alias Mikepayne14(Codeforces,Atcoder) 
                           qaseem_hasan_ (Codechef,HackerRank,HackerEarth)
*/


#include <bits/stdc++.h>
using namespace std;
//---------------------------------------------------------

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vpii;
typedef priority_queue <int, vector<int>, greater<int>> revpq;

const int INF = (int)1e9;
const int EPS = 1e-6;
const int mod  = 1000000007;
const long double PI = 3.14159265359;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

#define acc accumulate
#define eb emplace_back
#define F first
#define S second
#define MP make_pair
#define filcon(v,x) iota(all(v),x)
#define repi(n) for(int i=0;i<n;++i)
//#define erase(v,e) v.erase(std::remove(v.begin(), v.end(), e), v.end())
#define sqr(x) ((x)*(x))
#define MEM(a,b) memset(a, b, sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
// #define min_all(a,b,c,d,...) min({a,b,c,d,...})
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define make_unique(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define printv(v) for(auto i:v) cout << i << " "
#define trace(x) cout<<#x<<" = { "<<x<<" }"<<khatam
#define khatam '\n'
#define test int t; cin >> t; repi(t) {solve(); cout << khatam;}
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
for ( \
    auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
    blockTime.second; \
    debug("%s: %ld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
)


//--------------------------------------------------------

inline bool grid_inside(int x, int y, int n, int m) {return x >= 1 && x <= n && y >= 1 && y <= m;}

template<typename T>
T lcm(T a,T b)
{
    return (a*b)/__gcd(a,b);
}

template <typename T> T Dis(T x1,T y1,T x2, T y2)
{return sqrt(sqr(x1-x2) + sqr(y1-y2));}

template <typename T> T Angle(T x1,T y1,T x2, T y2)
{return atan((double)(y1-y2) / (double)(x1-x2));}

inline int Set(int N,int pos){ return N=N | (1<<pos);}
inline int Reset(int N,int pos){return N= N & ~(1<<pos);}
inline bool Check(int N,int pos){return (bool)(N & (1<<pos));}
template< class T, class X > inline T togglebit(T a, X i) { T t=1;return (a^(t<<i));}

//--------------------------------------------------------

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.F < j.F;
}

int LSOne(ll n){
    return log2(n & -n) + 1;
}

int rangeClear(int n,int i,int j){
    int ones = ~0;
    int a = ones << (j+1);
    int b = (i<<2)-1;
    int mask = a|b;
    int ans = n&mask;
    return ans;
}

ll mul_mod(ll x,ll y,ll mod){
    ll i=0,j=x;
    while(y>0){
        if(y&1)
        {
            i = (i+j)%mod;
        }
        j = (j+j)%mod;
        y>>=1;
    }
    return i;
}
ll fast_power(int a,int x)
{
    if(x==0)
        return 1;
    else if(x==1)
        return a;
    else
    {
        ll R = fast_power(a,x>>1);
        if(!(x&1))
            return R*R;
        else
            return R*a*R;
    }
}

ll fast_power_unlocked(ll a,ll n,ll mod)
{
    ll res = 1;
    while(n > 0)
    {
        if(n&1)
        {
            res = mul_mod(res,a,mod);
        }
        a = mul_mod(a,a,mod);
        n = n >> 1;
    }
    return res;
}

ll modInverse(ll A,ll M)
{
    return fast_power_unlocked(A,M-2,M);
}


/*const int MAX_N=10000;
bitset<MAX_N> isPrime;
void sieve()
{
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i*i<=MAX_N;i++)
    {
        if(isPrime[i])
        {
            for(ll j=i*i;j<=MAX_N;j+=i)
            {
                isPrime[j] = 0;
            }
        }
    }
}*/
const int maxn = 3005;
ll dp[maxn][maxn];
int a[maxn];
ll findX(int i,int j,int turn)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(turn==0) return dp[i][j] = max(findX(i+1,j,1)+a[i],findX(i,j-1,1)+a[j]);
    else return dp[i][j] = min(findX(i+1,j,0),findX(i,j-1,0));
}

void  solve()
{
    int n;
    cin >> n;
    MEM(dp,-1);
    ll sm=0;
    for(int i=0;i<n;i++) {cin >> a[i]; sm+= a[i];}
    ll x = findX(0,n-1,0);
    ll y = sm-x;
    cout << x-y;
}

int main()
{
    FAST_IO;

//-------------------------------------------------------
        time__("Time Taken"){
        solve();
    }
}

