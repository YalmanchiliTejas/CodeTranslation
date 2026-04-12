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
const int mod = 1e9 + 7;
const int oo = 1e9;
const ll OO = 1e18;
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
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
template <typename T, size_t N>
std::istream& operator >>(std::istream& in, array<T, N>& a) {
  for (size_t i = 0; i < N; i++) in >> a[i];
  return in;
}
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
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr <<"[" << name << ": " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr << "[";
  cerr.write(names, comma - names) << ": " << arg1 << "]  ";
  __f(comma + 2, args...);
}
template <typename Arg1>
void print(Arg1&& arg1){
	cout << arg1 << endl;
}
template <typename Arg1, typename... Args>
void print(Arg1&& arg1, Args&&... args){
  cout << arg1 << ' ';
  print(args...);
}
template <typename Arg1>
void read(Arg1&& arg1){
	cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1&& arg1, Args&&... args){
  cin >> arg1;
  read(args...);
}
int nextInt() { int x; read(x); return x; }
ll nextLong() { ll x; read(x); return x; }

class Timer {
	string _name;
	clock_t _start;
public:
	Timer(string name = "Runtime") { _name = "["+name+": ", _start = clock(); }
	~Timer() { cerr << _name << double(clock() - _start)/CLOCKS_PER_SEC << "]\n"; }
};

#ifdef ONLINE_JUDGE
#undef CASE_INFO
#endif

void solve() {
	long long n;
	int x, m;
	read(n, x, m);
	vector<bool> vis(m);
	vector<int> a;
	while(!vis[x]) {
		a.pb(x);
		vis[x] = 1;
		x = 1ll*x*x%m;
	}
	int pos = find(a.begin(), a.end(), x) - a.begin();
	if(n <= a.size()) {
		print(accumulate(a.begin(), a.begin() + n, 0ll));
		return;
	}
	n -= pos;
	print(
			accumulate(a.begin(), a.begin() + pos + (n % (a.size() - pos)), 0ll) +
			1ll*(n / (a.size() - pos)) * accumulate(a.begin() + pos, a.end(), 0ll)
			// - ( (n % (a.size() - pos) == 0) ? a[pos] : 0)
			);
}

signed main() {
	Timer ti;
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	#ifdef TEST_CASES
	cin >> T;
	#endif
	for(int tt = 1; tt <= T; tt++) {
		#ifdef CASE_INFO
		cout << "Case #" << tt << ": ";
		#endif
		solve();
	}
	return 0;
}
