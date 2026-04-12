#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define repi(n) for(int i = 0; i < (n); i++)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define all(p) p.begin(), p.end()
#define pop_count(p) __builtin_popcountll(p)
#define len(s, e) ((e)-(s)+1)
#define mid(s, e) ((s)+((e)-(s))/2)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const int MOD = 1e9 + 7;
const int oo = 987654321;
const ll OO = 1e18;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
template <typename A, typename B>
std::ostream& operator <<(std::ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
std::ostream& operator <<(std::ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
std::ostream& operator <<(std::ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
std::ostream& operator <<(std::ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
template <typename T>
std::ostream& operator <<(std::ostream& out, const list<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename A, typename B>
std::istream& operator >>(std::istream& in, pair<A, B>& a) {
	in >> a.first >> a.second;
  return in;
}
template <typename T>
std::istream& operator >>(std::istream& in, vector<T>& a) {
  for (auto& v : a) in >> v;
  return in;
}
#ifdef ANEEE_LOCAL
template <typename T>
std::ostream& operator <<(std::ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
#else
template <typename T>
std::ostream& operator <<(std::ostream& out, const vector<T>& a) {
  for (const auto& v : a) out << v << ' ';
  return out;
}
#endif
#ifdef ANEEE_LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 7
#endif
#define printin(...) __g(__VA_ARGS__)
#define print(...) __h(__VA_ARGS__)
#define read(...) __i(__VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename Arg1>
void __g(Arg1&& arg1){
	cout << arg1;
}
template <typename Arg1, typename... Args>
void __g(Arg1&& arg1, Args&&... args){
  cout << arg1 << ' ';
  __g(args...);
}
template <typename Arg1>
void __h(Arg1&& arg1){
	cout << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __h(Arg1&& arg1, Args&&... args){
  cout << arg1 << ' ';
  __h(args...);
}
template <typename Arg1>
void __i(Arg1&& arg1){
	cin >> arg1;
}
template <typename Arg1, typename... Args>
void __i(Arg1&& arg1, Args&&... args){
  cin >> arg1;
  __i(args...);
}

class Timer {
	clock_t start;
public:
	Timer() {start = clock();}
	~Timer() {cerr << (double)(clock() - start)/CLOCKS_PER_SEC << "\n";}
};

struct mint {
	int v = 0;
	int mod = 1000000007;
	mint() {}
	template <typename X> mint(X n) : v(n), mod(1000000007) {
		if(-mod <= v and v < 0) { v += mod; }
		else if(0 <= v and v < mod) { }
		else if(mod <= v and v < 2*mod) { v -= mod; }
		else { v %= mod; }
	}
	template <typename X, typename Y> explicit mint(X n, Y n_mod) : v(n), mod(n_mod) {
		if(-mod <= v and v < 0) { v += mod; }
		else if(0 <= v and v < mod) { }
		else if(mod <= v and v < 2*mod) { v -= mod; }
		else { v %= mod; }
	}
	friend mint operator+(const mint& a, const mint& b) { assert(a.mod == b.mod); return mint(a.v + b.v, a.mod); }
	friend mint operator-(const mint& a, const mint& b) { assert(a.mod == b.mod); return mint(a.v - b.v, a.mod); }
	friend mint operator*(const mint& a, const mint& b) { assert(a.mod == b.mod); return mint(static_cast<int>(1ll * a.v * b.v % a.mod), a.mod); }
	friend mint &operator+=(mint& a, const mint& o){ a = a + o;  return a; }
	friend mint &operator-=(mint& a, const mint& o){ a = a - o;  return a; }
	friend mint &operator*=(mint& a, const mint& o){ a = a * o;  return a; }
	friend mint &operator++(mint& a) { a.v++; if(a.v == a.mod) { a.v = 0; } return a; }
	friend mint &operator--(mint& a) { if(a.v == 0) { a.v = a.mod; } a.v--; return a; }
	template <typename X> mint pow(X b) const {
		assert(v >= 0);
		mint ret(1, mod);
		mint a(*this);
		while(b) {
			if(b & 1) ret *= a;
			a *= a;
			b >>= 1;
		}
		return ret;
	}
	friend mint operator/(const mint& a, const mint& b) { return a * b.pow(b.mod-2); }
	friend mint &operator/= (mint& a, const mint& b){ a = a / b; return a; }

	bool operator< (const mint& o) const { return v < o.v; }
	bool operator> (const mint& o) const { return v > o.v; }
	bool operator<= (const mint& o) { return v <= o.v; }
	bool operator>= (const mint& o) { return v >= o.v; }
	bool operator== (const mint& o) { return v == o.v; }
	bool operator!= (const mint& o) { return v != o.v; }
	friend istream &operator>>(istream &in, mint &c) { in >> c.v; return in; }
	friend ostream &operator<<(ostream &ou, const mint &c) { ou << c.v; return ou; }
};

#ifdef ONLINE_JUDGE
#undef CASE_INFO
#endif

void solve() {
	int n;
	read(n);
	vector<mint> a(n);
	read(a);
	vector<mint> pre(n+1);
	pre[0] = 0;
	for(int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i];
	}
	mint ans = 0;
	for(int i = 0; i < n; i++) {
		ans += a[i] * (pre[n] - pre[i+1]);
	}
	print(ans);
}

signed main() {
	Timer ti;
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	#ifdef TEST_CASES
	cin >> T;
	#endif
	for(int t = 1; t <= T; t++) {
		#ifdef CASE_INFO
		cout << "Case #" << t << ": ";
		#endif
		solve();
	}
	return 0;
}
