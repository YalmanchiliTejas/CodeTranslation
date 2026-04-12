#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	set<int>s;
	vector<int>v(N);
	for (int i = 0; i < N; i++)v[i] = i;
	vector<pair<int, int>>w(K);
	for (auto &i : w) {
		cin >> i.first >> i.second;
		i.first--;
		i.second--;
	}
	for (int i = K - 1; i >= 0; i--) {
		swap(v[w[i].first], v[w[i].second]);
	}
	int p = 0;
	s.insert(v[0]);
	s.insert(v[1]);
	for (auto i : w) {
		swap(v[i.first], v[i.second]);
		if (i.first == p)p = i.second;
		else if (i.second == p)p = i.first;
		if (p - 1 >= 0)s.insert(v[p - 1]);
		if (p + 1 < N)s.insert(v[p + 1]);
	}
	cout << s.size() << endl;
}