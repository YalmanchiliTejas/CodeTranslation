// スタックサイズ: 100MB

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
using namespace std;

typedef int64_t ll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()




int main() {

	ll N, M;
	cin >> N >> M;
	vector<pair<ll, ll>> ab(M);
	vll vtx(N);
	rep(i, M) {
		ll a, b; cin >> a >> b;
		ab[i] = pair<ll, ll>(a, b);
	}
	sort(all(ab));
	rep(i, N) vtx[i] = i + 1;

	ll ans = 0;
	do {
		bool flag = true;
		rep(i, N - 1) {
			pair<ll, ll> tmp1 = pair<ll, ll>(vtx[i], vtx[i + 1]);
			pair<ll, ll> tmp2 = pair<ll, ll>(vtx[i + 1], vtx[i]);
			if (!binary_search(all(ab), tmp1) && !binary_search(all(ab), tmp2)) flag = false;
		}
		if (flag) ++ans;

	} while (next_permutation(vtx.begin() + 1, vtx.end()));
	
	cout << ans << endl;
}