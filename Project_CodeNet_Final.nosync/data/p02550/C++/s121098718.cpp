#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; using ld = long double; using ll = long long;
using ull = unsigned long long;
#define endl "\n"
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define ALL(x) (x).begin(), (x).end()
int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1};
constexpr int INF=1<<30;
constexpr ll LINF=1LL<<60; 
constexpr ll mod=1e9+7;
void flush() {cout<<flush;}
template<class T>vector<T> vec(int len, T elem) { return vector<T>(len, elem); } // auto dp = vec(52, vec(103, vec(103, INF)));
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T>inline int popcount(T a) {return __builtin_popcountll(a);}
template<class T>inline T emod(T a, T p) { return (a%p + p) % p;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << '\n'; for (auto v : vec) os << v << ' '; os << '\n'; return os;}
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
struct MyIO {
    MyIO(){
        cin.tie(0); 
        ios::sync_with_stdio(false); 
        cout << fixed << setprecision(15);
    }
} IO_OI;
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
//-------------------
struct mint {
	ll x;
	mint(ll x=0):x(x%mod){}

	bool operator==(const mint a)const{return x==a.x;}
	bool operator!=(const mint a)const{return x!=a.x;}
	bool operator>=(const mint a){return (x >= a.x)? 1: 0;}
	bool operator<(const mint a){return !(*this>=a);}
	bool operator>(const mint a){return (x > a.x)? 1:0;}
	bool operator<=(const mint a){return !(*this>a);}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
			return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
			return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res+=a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res-=a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res*=a;
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res/=a;
	}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;  //2 square
		if (t&1) a *= *this; 
		return a;
	}
	// for prime mod
	mint inv() const {
		return pow(mod-2);
	}
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};
int main() {
    ll n,x,m;cin>>n>>x>>m;
    ll ans = 0;

    ll cnt = 0;
    unordered_map<int,int> mp;
    ll next = x;
    ll cur = 0;
    while(cnt<n and !mp.count(next)) {
        mp[next] = cnt;
        cur += next;
        next = (next*next) % m;
        cnt++;
    }
    if(cnt == n) {
        cout << cur << endl;
        return 0;
    }
    int prd = (cnt-mp[next]);
    ll tmp = 0;
    ll nt = x;
    rep(i, mp[next]) {
        tmp += nt;
        nt = (nt*nt) % m;
    }
    
    ans += tmp + (cur-tmp) * ((n-mp[next])/prd);
    debug(tmp, ans, cur , mp[next]);

    int resi = (n-mp[next])%prd;
    rep(i,resi) {
        ans += next;
        next = (next*next) % m;
    }

    cout << ans << endl;
}