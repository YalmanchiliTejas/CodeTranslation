#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl '\n'
#ifndef CODE_JAM
#undef CASE_INFO
#endif
#else
#pragma GCC optimize "trapv"
#endif
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define rep(n) for(int i = 0; i < n; i++)
#define repj(n) for(int j = 0; j < n; j++)
#define all(p) p.begin(), p.end()
#define count_1(p) __builtin_popcountll(p)
#define count_0(p) __builtin_ctzll(p)
template<class X>inline X mid(X s,X e){return (s+(e-s)/2);}
template<class X>inline X len(X s,X e){return (e-s+1);}
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
template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
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

class Timer {
	clock_t start;
public:
	Timer() {start = clock();}
	~Timer() {cerr << (double)(clock() - start)/CLOCKS_PER_SEC << "\n";}
};

void add_self(int& a, int b) {
	a += b;
	if(a >= MOD)
		a-=MOD;
}

void solve() {
	string s;
	cin >> s;
	int n = s.size(), d;
	cin >> d;
	vector<vector<int>> dp(d, vector<int>(2));
	dp[0][1]=1;
	for(int i = 0; i < n; i++) {
		vector<vector<int>> new_dp(d, vector<int>(2));
		for(int old_rem = 0; old_rem < d; old_rem++) {
			for(int num = 0; num < 10; num++) {
				int new_rem = (old_rem+ num) % d;
				add_self(new_dp[new_rem][0], dp[old_rem][0]);
				if(num < s[i]-'0') {
					add_self(new_dp[new_rem][0], dp[old_rem][1]);
				}
				else if(num == s[i]-'0') {
					add_self(new_dp[new_rem][1], dp[old_rem][1]);
				}
			}
		}
		dp=new_dp;
	}
	int ans = dp[0][0] + dp[0][1];
	if(ans >= MOD) ans -= MOD;
	ans--;
	if(ans < 0) ans += MOD;
	cout << ans << endl;
}

signed main() {
	Timer ti;
	ios_base::sync_with_stdio(false);
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
