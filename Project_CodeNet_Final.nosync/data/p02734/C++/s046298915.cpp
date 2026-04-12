#include <iostream>
#include <sstream>
#include <bitset>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;


int main(int argc, char *argv[]) {
	int n, s;
	cin >> n >> s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	const int mod = 998244353;
	unordered_map<int, pair<long long int, long long int>> um1, um2;
	// [count][index sum]
	um1[0] = make_pair(0, 0);
	long long int res = 0;
	for (int i = 0; i < n; i++) {
		um2 = um1;
		for (auto p : um1) {
			if (p.first == 0) {
				if (v[i] == s) {
					res += (i + 1) * (n - i) % mod;
					res %= mod;
					continue;
				}
				um2[v[i]].first += 1;
				um2[v[i]].second += i;
				continue;
			}
			if (p.first + v[i] < s) {
				um2[p.first + v[i]].first += p.second.first;
				um2[p.first + v[i]].first %= mod;
				um2[p.first + v[i]].second += p.second.second % mod;
				um2[p.first + v[i]].second %= mod;
			} else if (p.first + v[i] == s) {
				res += (p.second.second + p.second.first) % mod * (n - i) % mod;
				res %= mod;
			}
		}
		um1 = um2;
	}
	cout << res << endl;
}







