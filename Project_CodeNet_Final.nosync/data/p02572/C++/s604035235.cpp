#include "bits/stdc++.h"

using namespace std;

//typedefs
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

//#Defines
#define pb push_back
// #define pb emplace_back
#define F first
#define S second
#define all(c)      c.begin(),c.end()
// #define endl '\n'
#define pf printf
#define sf scanf
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)
//if harmonic numbers need to be calculated, precalculate upto 1e6, then for any x > 1e6
//call harmonic(x + 0.5)
#define RESET(a,b)  memset(a,b,sizeof(a))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

//Rotation: S -> E -> N -> W
int fx[] = {0, +1, 0, -1};
int fy[] = {-1, 0, +1, 0};
//int dx[] = {0, +1, +1, +1, 0, -1, -1, -1};
//int dy[] = {-1, -1, 0, +1, +1, +1, 0, -1};

//Inline functions
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }

inline void normal(ll &a) { if (a >= MOD) a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) {normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) {normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) {normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; } //if MOD is prime, modPow(b, p % (MOD-1))
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


inline bool isInside(pii p,ll n,ll m)   { return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); }
inline bool isInside(pii p,ll n)        { return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); }
inline bool isSquare(ll x)              { ll s = sqrt(x);   return (s*s==x); }
inline bool isFib(ll x)                 { return isSquare(5*x*x+4)|| isSquare(5*x*x-4); }
inline bool isPowerOfTwo(ll x)          { return ((1LL<<(ll)log2(x))==x); }
inline ll gcd(ll a, ll b) {return __gcd(a, b);}
inline ll lcm(ll a, ll b) {return (a * (b / gcd(a, b))); }

struct custom_hash {
    //when creating an unordered_map, set the third template type as custom_hash
    //ex: unordered_map<int, int, custom_hash> mp;
    //https://codeforces.com/blog/entry/62393
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


/*
Java
Long and long are different
if we want to conver x to base b
call Long.toString(x, b);
*/

//Prime Number Generator
/*
#define mx 1000006
bitset <mx> mark;
vector <int> primes;

void sieve() {
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mx * 1.0) + 2;
    for (int i = 4; i < mx; i += 2) mark[i] = 1;
    for (int i = 3; i < mx; i += 2) {
        if (!mark[i]) {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mx; j += i)
                    mark[j] = 1;
        }
    }
}
*/

int main() {
    #ifdef ROBIN
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif // ROBIN


    int n; cin >> n;
    ll ans = 0;

    vector <ll> v(n, 0), c(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        c[i] = v[i];
        if (i > 0) c[i] = modAdd(c[i], c[i - 1]);
    }

    for (int i = 1; i < n; i++) {
        ans = modAdd(ans, modMul(v[i], c[i - 1]));
    }

    cout << ans << endl;
}
