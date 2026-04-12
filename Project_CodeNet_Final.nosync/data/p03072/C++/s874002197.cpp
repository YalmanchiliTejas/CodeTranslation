#include <bits/stdc++.h>
using namespace std;
using lli = int_fast64_t;
using ulli = uint_fast64_t;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = x;cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl
template<typename T>
T ncr(T left, T right) {
	right = min(left - right, right);
	T ans = 1;
	for (T i = 1; i <= right; i++) {
		ans = ans * (left - right + i) / i;
	}
	return ans;
}

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
	int ma = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (ma <= v[i]) {
			ma = v[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

