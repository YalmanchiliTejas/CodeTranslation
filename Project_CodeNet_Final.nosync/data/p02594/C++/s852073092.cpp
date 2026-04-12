#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#define ll long long int
#define ar array
#define ld long double
#define bigint int64_t
#define vll vector<ll>
#define pll ar<ll,2>
#define vpll vector<pll>
#define pb push_back
#define sz(x) (int)(x).size()
#define MOD 1000000007
#define ff first
#define ss second
#define en cout<<"\n"
#define LCM(a,b) (a*(b/__gcd(a,b)))
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define test          int t;cin>>t;while(t--)
#define umi        unordered_map<int,int>
#define maxheap    priority_queue<int>
#define minheap    priority_queue<int,vector<int>,greater<int> >
#define lb(v,val)  (lower_bound(v.begin(),v.end(),val)-v.begin())
#define ub(v,val)  (upper_bound(v.begin(),v.end(),val)-v.begin())
#define INF (ll)(1e18)
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ini(a,b) memset(a,b,sizeof(a))
#define vvll vector<vector<ll>>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MEM(a, b) memset(a, b, sizeof(a))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define MAXN (int)(1 * 1e6 + 10)
#define prec(n) fixed<<setprecision(n)
#define deb1(x)                cerr<<#x<<": "<<x<<endl
#define deb2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define GET5(a, b, c, d, e, ...) e
#define each(x, a) for (auto& x: a)
#define D_EBC(...) GET5(__VA_ARGS__, deb4, deb3, deb2, deb1)
#define deb(...) D_EBC(__VA_ARGS__)(__VA_ARGS__)
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define forn(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
double eps=0.000001;
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T> using mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
void read(T &x) {
    cin >> x;
}
template <typename T , typename T0>
void read(T &x, T0 &y) {
    cin >> x >> y;
}
 
template <typename T , typename T0 , typename T1>
void read(T &x, T0 &y, T1 &z) {
    cin >> x >> y >> z;
}
 
template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
    cin >> x >> y >> z >> w;
}
 
template <typename T , typename T0>
void read(pair< T , T0 > &p) {
    cin >> p.fst >> p.scd;
}
 
template <typename T>
void read(vector< T > &oneD, ll n) {
    for (ll i = 0; i < n; i++) {
        read(oneD[i]);
    }
 
}
 
template <typename T>
void read(T oneD[] , ll n) {
    for (ll i = 0; i < n; i++) {
        read(oneD[i]);
    }
}
 
template <typename T>
void write(T &x) {
 
    cout << x << " ";
}
 
template <typename T , typename T0>
void write(T &x, T0 &y) {
    cout << x << " " << y << "\n";
}
 
template <typename T , typename T0 , typename T1>
void write(T &x, T0 &y, T1 &z) {
    cout << x << " " << y << " " << z << "\n";
}
 
template <typename T , typename T0 , typename T1 , typename T2>
void write(T &x, T0 &y, T1 &z, T2 &w) {
    cout << x << " " << y << " " << z << " " << w << "\n";
}
 
template <typename T , typename T0>
void write(pair< T , T0 > &p) {
    write(p.fst);
    write(p.scd);
    cout << endl;
}
 
template <typename T>
void write(vector< T > &oneD) {
    for (ll i = 0; i < oneD.size(); i++) {
        write(oneD[i]);
    }
    cout << endl;
}
 
template <typename T>
void write(T oneD[] , int n) {
    for (ll i = 0; i < n; i++) {
        write(oneD[i]);
    }
    cout << endl;
}
 
template <typename T , typename T0>
void write(map< T , T0 > &mpp) {
    for (auto it : mpp) {
        write(it.fst);
        cout << ": ";
        write(it.scd);
        cout << "\n";
    }
    cout << endl;
}
inline bool isSquare(ll x)
{
    ll s = sqrt(x);
    return (s * s == x);
}
inline bool isFib(ll x)
{
    return isSquare(5 * x * x + 4) || isSquare(5 * x * x - 4);
}
inline bool isPowerOfTwo(ll x)
{
    return ((1LL << (ll)log2(x)) == x);
}
 
ll extended_GCD(ll a , ll b , ll &x , ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b % a , a , x1 , y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
 
vector<ll> prime;
 
void sieve(ll N){
    bool isPrime[N+!1];
 
    for(ll i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i = 2; i * i <= N; ++i) {
            if(isPrime[i] == true) {   
                for(ll j = i * i; j <= N ;j += i)
                    isPrime[j] = false;
        }
    }
 
    for(ll i =2;i<=N;i++) {
        if(isPrime[i] == true) {
            prime.push_back(i);
        }
    }
}
 
 
ll minPrime[MAXN];
void factorSieve(ll n){
    memset(minPrime,0,sizeof(minPrime));
    for (ll i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (ll j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}
 
ll factorize(ll n) {
 
    map<ll,ll> m;
    m.clear();
    while (n != 1) {
        m[minPrime[n]]++;
        n /= minPrime[n];
    }
 
    for(auto i:m) {
        if(i.second>1) {
            return 0;
        }
    }
 
    return 1;
}
ll modinv(ll a , ll mod = MOD) {
    ll x , y, g;
    g = extended_GCD(a , mod , x , y);
    if (g != 1)
        return -1;
    else
    {
        if (x < 0) x += mod;
        return x;
    }
}
 
//Chinese Remainder Theoram
ll find_x_CRT(ll num[], ll rem[], ll n)
{
    ll pro = 1;
    forn(i, n)
    pro *= num[i];
    ll res = 0;
    forn(i, n)
    {
        ll pp = pro / num[i];
        res += (rem[i] * modinv(pp, num[i]) * pp);
    }
    res %= pro;
    return res;
}
 
ll power(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
ll mulmod(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 0;
    while (b > 0) {
        if (b & 1)
            res = (res%m + a%m) % m;
        a = (a * 2 )% m;
        b >>= 1;
    }
    return res%m;
}
 
void precompute_NCR(vll &fact)
{
    const ll N = 1e6 + 5;
    fact[0] = 1;
    forn(i, 1, (N - 1), 1)
    {
        ll y = (i % MOD * fact[i - 1] % MOD) % MOD;
        fact[i] = y;
    }
}
 
ll NCR(vll &fact, ll N, ll R, ll mod = MOD)
{
    ll n = fact[N];
    ll r = fact[R];
    ll n_r = fact[N - R];
    ll y = (r % mod * n_r % mod) % mod;
    ll z = modinv(y, mod);
    ll ans = (n % mod * z % mod) % mod;
    return ans;
}
 
string to_string(char c) {
    return string(1, c);
}
 
struct comp {
bool operator()(pair<ll,ll> a, pair<ll,ll> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}  
};
 
bool cmp (pll a, pll b) {
    if(a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] > b[0];
}  
// const int fx[] = {0, +1, 0, -1};
// const int fy[] = {-1, 0, +1, 0};
// const ll N=1e6;
// ll dp[N+1];

void solve(){
    ll n;
    read(n);
    if(n>=30) cout<<"Yes";
    else
        cout<<"No";
}
int main() {
    fast;
    int t=1;
    // read(t);
    forn(t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
}
