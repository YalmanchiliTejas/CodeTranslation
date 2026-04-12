#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	cin >> n;
	
	vector<string> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	
	vector<int> cnt(26, 100);
	for(int i = 0; i < n; ++i) {
		vector<int> tmp(26, 0);
		
		for(int j = 0; j < (int)s[i].size(); ++j) {
			tmp[s[i][j] - 'a']++;
		}
		
		for(int j = 0; j < 26; ++j) {
			cnt[j] = min(cnt[j], tmp[j]);
		}
	}
	
	string ans = "";
	for(int i = 0; i < 26; ++i) {
		for(int j = 0; j < cnt[i]; ++j) {
			ans += (char)(i + 'a');
		}
	}
	
	if( ans == "" ) {
		cout << " " << endl;
	} else {
		cout << ans << endl;
	}
	
	return 0;
}
