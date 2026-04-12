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

void Main() {
	ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	ll res = numeric_limits<ll>::max();
	for(int i = 0; i <= max(x, y) * 2; i += 2) {
		res = min(res, max((x - i / 2), 0LL) * a + max((y - i / 2), 0LL) * b + i * c);
	}
	cout << res << endl;
}

int main() {
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
