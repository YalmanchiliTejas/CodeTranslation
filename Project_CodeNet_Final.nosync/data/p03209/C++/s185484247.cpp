#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(obj)   (obj).begin(),(obj).end()

#define debug(var)  do{std::cout << __LINE__ << "> " << #var << ": ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;


ll rec(int level, ll x, const vl &thicks, const vl &pats) {
	if (level == 0) {
		return x <= 0 ? 0 : 1;
	} 
	if (thicks[level] / 2 >= x) {
		return rec(level - 1, x - 1, thicks, pats);
	} else if (thicks[level] / 2 + 1 == x) {
		return pats[level - 1] + 1;
	} else if (thicks[level] > x) {
		return pats[level - 1] + 1 + rec(level - 1, x - 2 - thicks[level - 1], thicks, pats);
	} else {
		return pats[level];
	}
}

void Main() {
	ll N, X; cin >> N >> X;
	vl thicks(N + 1);
	vl pats(N + 1);
	thicks[0] = 1;
	pats[0] = 1;
	FOR(i, 1, N + 1) {
		thicks[i] = thicks[i - 1] * 2 + 3;
		pats[i] = pats[i - 1] * 2 + 1;
	}
	cout << rec(N, X, thicks, pats) << endl;
	// debug(thicks);
	// debug(pats);
}

int main() {
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
