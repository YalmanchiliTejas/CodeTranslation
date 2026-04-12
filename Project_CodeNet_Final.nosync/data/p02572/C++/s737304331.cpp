#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <map>
#include <list>
#include <climits>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <string>

// #define cerr if(false)cerr
#define watch(x) cerr << "> " << #x << ": " << x << "\n";

using namespace std;

template <typename T>
std::ostream &operator <<(std::ostream &out, vector<T> &v) {
	for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
		out << v[i] << " ";
	out << "\n";
    return out;
}
template <typename T, typename N>
std::ostream &operator <<(std::ostream &out, vector<pair<T, N> > &v) {
	for (size_t i = 0; i < v.size(); ++i)
		out << "(" << v[i].first << ", " << v[i].second << ") ";
	out << "\n";
    return out;
}
template <typename T>
std::ostream &operator <<(std::ostream &out, vector<vector<T> > &v) {
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t j = 0; j < v[i].size(); ++j) {
			out << v[i][j] << " ";
		}
		out << "\n";
	}
   	return out;
}

constexpr long long mod = 1e9 + 7;

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> a(n + 1), pre_sum(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pre_sum[i] = pre_sum[i - 1] + a[i];
	}

	long long sum = 0;
	for (int i = 1; i < n; ++i) {
		sum += a[i] * ((pre_sum[n] - pre_sum[i]) % mod);
		sum %= mod;
	}

	cout << sum << "\n";

	return 0;

}