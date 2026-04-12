#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i)++)
typedef pair<long long , long long> P;
int main() {
	long long N;
	cin >> N;
	vector<string>S(N);
	vector<vector<long long>>A(N, vector<long long>(26, 0));
	rep(i, N) {
		cin >> S.at(i);
		rep(j, S.at(i).size()) {
			int num = S.at(i).at(j) - 97;
			A.at(i).at(num)++;
		}
	}
	vector<int>ans(26, 0);
	rep(i, 26) {
		long long num = 1e9;
		rep(j, N) {
			num = min(num, A.at(j).at(i));
		}
		ans.at(i) = num;
	}
	rep(i, 26) {
		if (ans.at(i) != 1e9) {
			rep(j, ans.at(i)) {
				cout << char('a' + i);
			}
		}
	}
	cout << endl;
}