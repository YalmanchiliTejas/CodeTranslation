#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n;

ll score(vector<int> & p) {
	ll score = 0;
	rep(i, n - 1) {
		score += abs(p[i] - p[i + 1]);
	}
	return score;
}

void dump(vector<int> & p) {
	cout << "----" << endl;

	rep(i, n) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main() {

	cin >> n;

	ll a[n];
	rep(i, n) {
		cin >> a[i];
	}
	sort(&a[0], &a[n]);

	ll total = 0;



	if (n % 2 == 0) {
		vector<int> ans;
		for (int i = 0; i < n / 2; i++) {
			ans.push_back(a[n / 2 - i - 1]);
			ans.push_back(a[n - i - 1]);
		}
		cout << score(ans) << endl;
	} else {
		vector<int> ans0;
		for (int i = 0; i < n / 2; i++) {
			ans0.push_back(a[n / 2 - i - 1]);
			ans0.push_back(a[n / 2 + 1 + i]);

		}
		//dump(ans0);
		ans0.push_back(a[n / 2]);

		vector<int> ans1;
		for (int i = 0; i < n / 2; i++) {
			ans1.push_back(a[n / 2 + 1 + i]);
			ans1.push_back(a[n / 2 - i - 1]);
		}
		ans1.push_back(a[n / 2]);
		//dump(ans1);

		cout << max(score(ans0), score(ans1)) << endl;
	}
	

	return 0;
}