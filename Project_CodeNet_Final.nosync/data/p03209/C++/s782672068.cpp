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

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long x;
	cin >> x;

	long long patties = (1LL << (n + 1)) - 1;
	long long burger_size = 2 * patties - 1;
	long long ans = 0;
	long long low = 1, high = burger_size;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (mid == x) {
			ans += patties / 2 + 1;
			break;
		}
		else if (mid < x) {
			ans += patties / 2 + 1;
			low = mid + 1;
			--high;
		} else {
			high = mid - 1;
			++low;
		}

		--n;
		patties = (1LL << (n + 1)) - 1;
	}

	cout << ans << "\n";

	return 0;

}