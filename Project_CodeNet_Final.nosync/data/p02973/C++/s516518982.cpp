#include <bits/stdc++.h>

using namespace std;
using lli = int_fast64_t;
using ulli = uint_fast64_t;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = x;cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl

const lli MOD = 1000000007;
const lli LIMIT = 1000000000000000000 * 5;
const int tenfive = 100000;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	map<int,int, greater<>> se;
	for (int i = 0; i < N; i++) {
		int change = -1;
		auto it = se.upper_bound(v[i]);
		if (it != se.end()) {
			change = (*it).first;
		}
		if (change != -1) {
			se[change]--;
			if (se[change] == 0) {
				se.erase(change);
			}
		}
		se[v[i]]++;
	}

	int ans = 0;
	for (auto a : se) {
		ans += a.second;
	}
	cout << ans << endl;
	return 0;
}
