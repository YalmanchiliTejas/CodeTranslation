#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

// combination nCk（modなし）
// http://caprest.hatenablog.com/entry/2016/05/29/181102
ll comb(int n, int k){
	vector<vector<ll>> v(n+1,vector<ll>(n+1));
	for(int i = 0; i < v.size(); i++){
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for(int k = 1; k < v.size(); k++){
		for(int j = 1; j < k; j++){
			v[k][j] = v[k-1][j-1] + v[k-1][j];
		}
	}
	return v[n][k];
}

int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	if (n < k) {
		cout << 0 << endl;
		return 0;
	}
	
	ll ans = 0;
	for (int i = k; i <= n-1; i++) {
		ll now =  9 * comb(i-1, k-1);
		rep(j, k-1) now *= 9;
		ans += now;
	}
	int f0 = s[0]-'0', f1, f2;
	int non_zero_index1 = -1;
	int non_zero_index2 = -1;
	rep(i, n) {
		if(i == 0) continue;
		if(s[i] != '0') {
			non_zero_index1 = i;
			f1 = s[i]-'0';
			break;
		}
	}
	if (non_zero_index1 > 0) for(int i = non_zero_index1 + 1; i < n; i++) {
		if(s[i] != '0') {
			non_zero_index2 = i;
			f2 = s[i]-'0';
			break;
		}
	}
	if (k == 1) {
		ans += f0;
	} else if (k == 2) {
		// １ケタ目 == s[0]
		ll now1 = 0;
		if (non_zero_index1 > 0) now1 += f1;	// 2つ目がnon_zero_index1
		if (non_zero_index1 > 0 && non_zero_index1 < n-1) now1 += (n - non_zero_index1 - 1) * 9;	// 2つ目がnon_zero_index1未満
		// １ケタ目 != s[0]
		ll now2 = f0 - 1;
		now2 *= (n - 1) * 9;
		ans += now1 + now2;
	} else if (k == 3) {
		ll now1 = 0, now2 = 0, now3 = 0, now4 = 0;
		// １ケタ目 == s[0]
		if (non_zero_index1 > 0 && non_zero_index1 < n-1) {	// 2つ目がnon_zero_index1
			ll now2_1 = 0; // ２ケタ目 == f1
			if (non_zero_index2 > 0) now1 = f2; // 3つ目がnon_zero_index2
			if (non_zero_index2 > 0 && non_zero_index2 < n-1) now2_1 = (n - non_zero_index2 - 1) * 9; // 3つ目がnon_zero_index2未満
			
			ll now2_2 = f1 - 1; // ２ケタ目 != f1
			now2_2 *= (n - non_zero_index1 - 1) * 9;
			
			now2 = now2_1 + now2_2;
		}	
		if (non_zero_index1 > 0 && non_zero_index1 < n-2) now3 = comb((n - non_zero_index1 - 1), 2) * 9 * 9;	// 2つ目がnon_zero_index1未満
		
		// １ケタ目 != s[0]
		now4 = f0 - 1;
		now4 *= comb((n - 1), 2) * 9 * 9;
		ans += now1 + now2 + now3 + now4;
	}
	cout << ans << endl;
	return 0;
}