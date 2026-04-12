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
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>

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

	vector<vector<int> > occs(n, vector<int> (26));
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < (int) s.size(); ++j) {
			++occs[i][s[j] - 'a'];
		}
	}

	string ans = "";
	for (int i = 0; i < 26; ++i) {
		int curr_min = 1e5;
		for (int j = 0; j < n; ++j) {
			curr_min = min(curr_min, occs[j][i]);
		}

		for (int j = 0; j < curr_min; ++j) {
			ans.push_back(i + 'a');
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans << "\n";

	return 0;

}