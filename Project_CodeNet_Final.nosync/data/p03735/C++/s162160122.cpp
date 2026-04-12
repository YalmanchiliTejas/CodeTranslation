#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using tlli = tuple<ll, ll, int>;
static ll INF = 1000000000000000000ll;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pll> p(n);
	for(int i = 0; i < n; ++i){
		ll a, b;
		cin >> a >> b;
		p[i] = pll(min(a, b), max(a, b));
	}
	set<tlli> rset, bset;
	for(int i = 0; i < n; ++i){
		rset.emplace(p[i].first, p[i].second, i);
		bset.emplace(p[i].second, p[i].first, i);
	}
	ll answer =
		(get<0>(*rset.rbegin()) - get<0>(*rset.begin())) *
		(get<0>(*bset.rbegin()) - get<0>(*bset.begin()));
	while(get<0>(*rset.begin()) < get<1>(*rset.begin())){
		const auto r = *rset.begin();
		const auto b = tlli(get<1>(r), get<0>(r), get<2>(r));
		rset.erase(r);
		rset.insert(b);
		bset.erase(b);
		bset.insert(r);
		const ll t =
			(get<0>(*rset.rbegin()) - get<0>(*rset.begin())) *
			(get<0>(*bset.rbegin()) - get<0>(*bset.begin()));
		answer = min(answer, t);
	}
	cout << answer << endl;
	return 0;
}

