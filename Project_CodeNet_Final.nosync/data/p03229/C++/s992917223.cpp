#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<int, int>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
	ll n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	deque<ll> d1, d2, d3, d4;

	int l = 0, r = n-1;
	while(l < r){
		d1.push_back(a[l]);
		++l;
		if(l == r) break;
		d1.push_back(a[r]);
		--r;
	}
	d3 = d1;
	d1.push_front(a[l]);
	d3.push_back(a[l]);

	l = 0, r = n-1;
	while(l < r){
		d2.push_back(a[r]);
		--r;
		if(l == r) break;
		d2.push_back(a[l]);
		++l;
	}
	d4 = d2;
	d2.push_front(a[l]);
	d4.push_back(a[l]);

	ll a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	for(int i = 1; i < n; ++i) a1 += abs(d1[i] - d1[i-1]);
	for(int i = 1; i < n; ++i) a2 += abs(d2[i] - d2[i-1]);
	for(int i = 1; i < n; ++i) a3 += abs(d3[i] - d3[i-1]);
	for(int i = 1; i < n; ++i) a4 += abs(d4[i] - d4[i-1]);

	cout << max(a1, max(a2, max(a3, a4))) << endl;
	return 0;
}