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

	deque<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	deque<int> arrangement;
	arrangement.push_back(a.front());
	a.pop_front();
	while (a.size()) {
		if (abs(arrangement.front() - a.front()) >= abs(arrangement.front() - a.back()) && 
			abs(arrangement.front() - a.front()) >= abs(arrangement.back() - a.front()) &&
			abs(arrangement.front() - a.front()) >= abs(arrangement.back() - a.back())) {
			arrangement.push_front(a.front());
			a.pop_front();
		} 
		else if (abs(arrangement.front() - a.back()) >= abs(arrangement.front() - a.front()) && 
				 abs(arrangement.front() - a.back()) >= abs(arrangement.back() - a.front()) &&
				 abs(arrangement.front() - a.back()) >= abs(arrangement.back() - a.back())) {
			arrangement.push_front(a.back());
			a.pop_back();
		}
		else if (abs(arrangement.back() - a.front()) >= abs(arrangement.front() - a.back()) && 
				 abs(arrangement.back() - a.front()) >= abs(arrangement.front() - a.front()) &&
				 abs(arrangement.back() - a.front()) >= abs(arrangement.back() - a.back())) {
			arrangement.push_back(a.front());
			a.pop_front();
		} else {
			arrangement.push_back(a.back());
			a.pop_back();
		}
	}

	long long sum = 0;
	for (int i = 1; i < n; ++i) {
		sum += abs(arrangement[i] - arrangement[i - 1]);
	}

	cout << sum << "\n";

	return 0;

}