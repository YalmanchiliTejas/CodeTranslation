#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> cnt(26,50);
	rep(i,n) {
		string s;
		vector<int> w_cnt(26,0);
		cin >> s;
		for (char w: s) {
			w_cnt[w - 'a']++;
		}
		rep(j,26) {
			cnt[j] = min(cnt[j], w_cnt[j]);
		}
	}
	rep(i,26) {
		rep(j,cnt[i]) cout << char(i+'a');
	}
	return 0;
}
