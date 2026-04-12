#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

int main() {
	ll N;
	cin >> N;
	vector<P> v(N);
	for (int i = 0;i < N;i++) {
		ll x;
		cin >> x;
		v[i] = P(x, i);
	}
	sort(v.begin(), v.end());
	vector<ll> ans(2);
	ans[0] = v[N / 2 - 1].first;
	ans[1] = v[N / 2].first;
	vector<ll> answer(N);
	for (int i = 0;i < N;i++) {
		if (i <= N / 2 - 1)
			answer[v[i].second] = ans[1];
		else
			answer[v[i].second] = ans[0];
	}
	for (int i = 0;i < N;i++)
		cout << answer[i] << endl;
	return 0;
}
