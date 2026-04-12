#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FOREACH(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define SIZE(v) ((int)(v).size())
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define ll long long
#define llint long long
#define pii pair<int, int>
#define UNVISITED -1


template<typename T>
string to_string(const vector<T>& vc, int w) {
	if(vc.empty()) return "";
	if(w + 1 == vc.size()) return to_string(vc[w]);
	return to_string(vc[w]) + "," + to_string(vc, w + 1);
}
 
template<typename T>
string to_string(const vector<T>& vc) {
	return "{" + to_string(vc, 0) + "}";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

const int MAX = 200200;
const ll mod = 1000000007;
ll A[MAX];

int main() {
	int N; scanf("%d", &N);
	REP(i, N) scanf("%lld", A + i);
	ll inv2 = (mod + 1)/2;
	ll ans = 0;
	REP(i, N) ans += A[i];
	ans %= mod;
	ans = (ans * ans)%mod;
	REP(i, N) {
		ans = (ans - (A[i]*A[i])%mod + mod)%mod;
	}
	ans = (ans * inv2)%mod;
	printf("%lld\n", ans);
}