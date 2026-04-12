// #pragma GCC optimize ("O3")
// #pragma GCC target   ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("Ofast,no-stack-protector")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC optimize ("fast-math")
// #pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
using namespace std;

typedef long long int      ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef vector<ll>         vl;
typedef vector<vl>         vvl;
typedef pair<ll,ll>        pll;
typedef vector<pll>        vpll;

#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define eb          emplace_back
#define fr(i,n)     for(ll i = 0; i < n; ++i)
#define frs(i,s,n)  for(ll i = s; i < n; ++i)
#define frb(i,s,e)  for(ll i = s; i <= e; ++i)
#define rfr(i,n)    for(ll i = n-1; i >= 0; i--)
#define frbr(i,e,s) for(ll i = e; i >= s; i--)
#define all(x)      (x).begin(), (x).end()
#define sz(x)       ((ll)(x).size())

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) 
{
  return '"' + s + '"';
}
 
string to_string(const char* s) 
{
  return to_string((string) s);
}
 
string to_string(bool b) 
{
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) 
{
  bool first = true;
  string res = "{";
  for(int i = 0; i < static_cast<int>(v.size()); i++) 
  {
    if(!first) 
       res += ", ";
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) 
{
  string res = "";
  for(size_t i = 0; i < N; i++) 
    res += static_cast<char>('0' + v[i]);
  return res;
}
 
template <typename A>
string to_string(A v) 
{
  bool first = true;
  string res = "{";
  for(const auto &x : v) 
  {
    if(!first) 
       res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) 
{
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) 
{
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) 
{
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << "]\n"; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
  cerr << to_string(H);
  if(sizeof...(T)) 
     cerr << ", "; 
  debug_out(T...);
}

clock_t start_time = clock();
double get_current_time() 
{
  return ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
} 

#ifdef LOCAL
#define dbg(...)       {cerr << "[" << #__VA_ARGS__ << "] = [", debug_out(__VA_ARGS__);}
#define dbg_arr(a,n)   {cerr << "[" << #a << "] = [ "; fr(i,n) cerr << a[i] << " "; cerr << "]\n";}
#define dbg_mat(m,r,c) {cerr << "[" << #m << "]:\n"; fr(i,r) {cerr << "[ "; fr(j,c) cerr << m[i][j] << " "; cerr << "]\n";}}
#define dbg_time()     {cerr << "\n" << "Time elapsed: " << get_current_time() << "\n\n\n";}
#else
#define dbg(x...)      {}
#define dbg_arr(a,n)   {}
#define dbg_mat(m,r,c) {}
#define dbg_time()     {}
#endif

const ld PI   = acos(-1);
const ld EPS  = 1e-9;
const ll INF  = 1e18;
const ll SINF = 1e9;
const ll MOD  = 1e9+7; // 998244353;
const ll MAX  = 100100;


template< const ll &mod >
struct modular 
{
    ll val;

    modular(ll v = 0) 
    {
        if (v < 0) v = v % mod + mod;
        if (v >= mod) v %= mod;
        val = v;
    }

    static ll inv_mod(ll a, ll m = mod) // Extended Euclidean algorithm
    {
        ll g = m, r = a, x = 0, y = 1;

        while (r != 0) 
        {
            ll q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    modular& operator+=(const modular &other) 
    {
        val -= mod - other.val;
        if (val < 0) val += mod;
        return *this;
    }

    modular& operator-=(const modular &other) 
    {
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }

    static unsigned fast_mod(ull x, unsigned m = mod) 
    {
        #if !defined(_WIN32) || defined(_WIN64)
                return unsigned(x % m);
        #endif
                // Optimized mod for Codeforces 32-bit machines.
                // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit unsigned int.
                unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
                unsigned quot, rem;
                asm("divl %4\n"
                    : "=a" (quot), "=d" (rem)
                    : "d" (x_high), "a" (x_low), "r" (m));
                return rem;
    }

    modular& operator*=(const modular &other) 
    {
        val = fast_mod(ull(val) * other.val);
        return *this;
    }

    modular& operator/=(const modular &other) 
    {
        return *this *= other.inv();
    }

    friend modular operator+(const modular &a, const modular &b) { return modular(a) += b; }
    friend modular operator-(const modular &a, const modular &b) { return modular(a) -= b; }
    friend modular operator*(const modular &a, const modular &b) { return modular(a) *= b; }
    friend modular operator/(const modular &a, const modular &b) { return modular(a) /= b; }

    modular& operator++() 
    {
        val = val == mod - 1 ? 0 : val + 1;
        return *this;
    }

    modular& operator--() 
    {
        val = val == 0 ? mod - 1 : val - 1;
        return *this;
    }

    modular operator++(int) { modular before = *this; ++*this; return before; }
    modular operator--(int) { modular before = *this; --*this; return before; }

    modular operator-() const 
    {
        return val == 0 ? 0 : mod - val;
    }

    bool operator==(const modular &other) const { return val == other.val; }
    bool operator!=(const modular &other) const { return val != other.val; }

    modular inv() const 
    {
        return inv_mod(val);
    }

    modular pow(ll p) const 
    {
        if (p < 0)
            return inv().pow(-p);

        modular a = *this, result = 1;

        while (p > 0) 
        {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    explicit operator ll() const { return val; }

    friend ostream& operator<<(ostream &os, const modular &m) 
    {
        return os << m.val;
    }

    inline friend string to_string(modular x) {return to_string(ll(x));}
};

using mint = modular<MOD>;


void pre()
{
  // factorizer::sieve();
  // prepare_factorials();
}

void solve()
{
  ll n; cin >> n; 
  vector < mint > v(n);
  fr(i, n)
  {
    ll x; cin >> x;
    v[i] = x; 
  }  
  mint ans;
  fr(i, n)
   ans += v[i];
  ans *= ans;
  fr(i, n)
   ans -= (v[i] * v[i]);
  ans /= 2;
  cout << ans << "\n";
}



signed main()
{  
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // cout << fixed << setprecision(15);

  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  pre();

  ll t = 1;
  // cin >> t;
  frb(CASE, 1, t)
  {
    // cout << "Case #" << CASE << ": ";
    // dbg(CASE);
    solve();
  }

  dbg_time();
  
  return 0;
}     
     
