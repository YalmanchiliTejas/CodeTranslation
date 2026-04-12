#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ulli = unsigned long long int;
#define debug(x) cerr << #x << ":" << x << endl

namespace atcoder {
	void judge_outer(bool judge_exp, string ok = "Yes", string ng = "No") {
		if (judge_exp) {
			cout << ok << endl;
		}
		else {
			cout << ng << endl;
		}
	}

	template<typename T>
	T ncr(T left, T right) {
		right = min(left - right, right);
		T ans = 1;
		for (T i = 1; i <= right; i++) {
			ans = ans * (left - right + i) / i;
		}
		return ans;
	}

	const int LIMIT = 1000000007;
	const int tenfive = 100000;


}

using namespace atcoder;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a;
	cin >> a;
	if (a == 7 || a == 5 || a == 3) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}