#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(bool b) { return to_string(int(b)); }
string to_string(char b) { return "'" + string(1, b) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) {
	string res = "{";
	for (const auto& x : v) res += (res == "{" ? "" : ", ") + to_string(x);
	return res + "}";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug(T...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define db(...) 42
#endif
typedef long long ll;
typedef long double ld;
struct JumpTable {
	struct Jump {
		int nex;
		// Initialize based on 0 steps.
		ll sum = 0;
	};
	inline Jump combine(const Jump& a, const Jump& b) {
		Jump res;
		res.nex = b.nex;
		res.sum = a.sum + b.sum;
		return res;
	}
	int logMaxSteps;
	vector<vector<Jump>> mat;
	// Constructs jump table on [0..n-1], assuming all queries are <= maxSteps steps.
	// Input jumps for one step.
	JumpTable(vector<Jump> oneStep, ll maxSteps) {
		logMaxSteps = 64 - __builtin_clzll(maxSteps);
		int n = oneStep.size();
		mat = vector<vector<Jump>>(logMaxSteps, vector<Jump>(n));
		mat[0] = oneStep;
		for (int p = 1; p < logMaxSteps; ++p)
			for (int i = 0; i < n; ++i)
				mat[p][i] = combine(mat[p - 1][i], mat[p - 1][mat[p - 1][i].nex]);
	}
	// Returns combine from highest power to lowest power from left to right.
	// E.g. combine(combine(combine(Jump(), mat[18][x]), mat[14][nex^18[x]]), ...)
	Jump jump(int x, ll steps) {
		assert(steps < (1LL << logMaxSteps));
		Jump ret;
		ret.nex = x;
		for (int p = logMaxSteps - 1; p >= 0; --p)
			if (steps & (1LL << p))
				ret = combine(ret, mat[p][ret.nex]);
		return ret;
	}
};
using Jump = JumpTable::Jump;
int main() {
	ll n;
	scanf("%lld", &n);
	int x, m;
	scanf("%d%d", &x, &m);
	vector<Jump> jump(m);
	for (int i = 0; i < m; ++i) {
		jump[i].nex = (ll)i * i % m;
		jump[i].sum = i;
	}
	JumpTable jt(jump, n);
	printf("%lld\n", jt.jump(x, n).sum);
}
