#include "bits/stdc++.h"
using namespace std;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
    os<<"("<<p.first<<", "<<p.second<<")";
    return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
    os<<"{";
    for(int i = 0;i < (int)v.size(); i++){
        if(i)os<<", ";
        os<<v[i];
    }
    os<<"}";
    return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define IOS ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define fill(a,b)  memset(a, b, sizeof (a))
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define has_bit(bit_mask, x) ((bit_mask) & (1Uint << (x)))
#define turn_on_bit(bit_mask, x) (bit_mask |= (1Uint << (x)))
#define turn_off_bit(bit_mask, x) (bit_mask &= (~(1Uint << (x))))
#define smallest_on_bit(bit_mask) (__builtin_ctzint((bit_mask) & (-(bit_mask))))
#define int long long
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const long long modb = 1000000007;
const long long inf = 0x3f3f3f3f3f3f3f3fLL; // Large int
const double oo = 1e15; // Large double
const double eps = 1e-8; // Small double, used for computational geometry
const double pi = acos(-1.0);

inline int gcd(int a, int b){ if (a == 0) return b; return gcd(b % a, a);}
inline int lcm(int a,int b){return (a*b)/gcd(a, b);}
inline bool isPerfectSquare(int x){ int s = sqrt(x); return (s*s == x);}
inline bool isFibonacci(int n){return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);} 
inline int add(int a, int b) {a += b; if(a >= modb) return a - modb; return a;}
inline int sub(int a, int b) {a -= b; if(a < 0) return a + modb; return a;}
inline int mul(int a, int b) {return ((((a%modb)*(b%modb))%modb)+modb)%modb;}
inline int numofdig(int i) {return i > 0 ? (int) log10l ((ld) i) + 1 : 1;}

/*void pre(){
    int fact[N],ifact[N];
    fact[0]=1,fact[1]=1;
    ifact[0]=1,ifact[1]=1;
    repA(i,2,N-1){
        fact[i]=mul(fact[i-1],i);
        ifact[i]=pwr(fact[i],modb-2);
    }
}

int comb(int n,int r){
    if(r>n)return 0;
    return mul(fact[n],mul(ifact[r],ifact[n-r]));
}*/

int pwr(int a,int b){
	a %= modb;
    int ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % modb;
        a = (a * a) % modb;
        b >>= 1;
    }
    return ans;
}

int32_t main(){
    IOS;
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE*/
    int t = 1;
    rep(tc,t){
        //cout<<"Case #"<<tc+1<<": ";
      int n,m;cin>>n>>m;
      if(n==m)cout<<"Yes\n";
      else cout<<"No\n";
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}

