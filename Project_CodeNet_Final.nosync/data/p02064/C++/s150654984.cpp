#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int ask(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << endl;
	cout << flush;
	cin >> i;
	return i;
}
signed main() {
	int N, S, T;;
	cin >> N >> S >> T;
	S--; T--;
	vector<int> res;
	int len = ask(S, T);


	vector<pair<int, int> > vp;
	for (int i = 0; i < N; i++) {
		if (i != S && i != T) {
			int a = ask(S, i);
			int b = ask(i, T);
			if (a + b == len) {
				vp.emplace_back(a, i);
			}
		}
	}
	vp.emplace_back(len, T);
	sort(vp.begin(), vp.end());

	
	res.push_back(S);
	res.push_back(vp[0].second);
	int cur = 0;
	for (int i = 1; i < vp.size(); i++) {
		int t = ask(vp[cur].second, vp[i].second);
		if (vp[cur].first + t + (len - vp[i].first) == len) {
			res.push_back(vp[i].second);
			cur = i;
		}

	}


	cout << "!";
	for (int i = 0; i < res.size(); i++) {
		cout << " " << res[i] + 1;
	}
	cout << endl;
	cout << flush;
}
