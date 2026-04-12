#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;

#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define ff first
#define ss second
#define allr(c) (c).rbegin(),(c).rend()
#define ifr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pof pop_front
#define pob pop_back
#define pb emplace_back
#define pf emplace_front
#define fstm(m,n,r) m.reserve(n);m.max_load_factor(r)
#define mp make_pair
#define mt make_tuple
#define inf LLONG_MAX
#define os tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
const double PI = acos(-1);
typedef complex<double> cd;
typedef long long ll;
ll gcd(){return 0ll;} template<typename T,typename... Args> T gcd(T a,Args... args) { return __gcd(a,(__typeof(a))gcd(args...)); }
typedef map<ll,ll> mll;
typedef map<string,ll> msll;
typedef unordered_map<ll,ll> umap;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mod 1000000007 

const int N = 1e5 + 2;

// source :- https://codeforces.com/blog/entry/63903

template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular power(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return power(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& ostr, Modular const& a) {return ostr << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    // #endif
    
    // int T;cin>>T;while(T--) 
    {
        int n, x;
        cin>>n;
        vector<Modular<mod>> a(n),b(n);
        ifr(i, 0, n) {
            cin>>x;
            a[i] = x;
        }
        b[n-1] = a[n-1];
        ifr(i, n-1, 0) 
            b[i] = a[i] + b[i+1];
        Modular<mod> ans;
        ifr(i, 0, n-1) {
            ans += a[i] * b[i+1];
        }
        cout<<ans<<endl;
    }
    return 0;
}