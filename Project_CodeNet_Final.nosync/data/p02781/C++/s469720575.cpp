#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string s;
	cin >> s;
	int k;
	cin >> k;
	reverse(s.begin(), s.end());
	s += '0';
	int cur = 0;
	while(true){
		if(s[cur] == '9'){
			s[cur] = '0';
			cur++;
		} else {
			s[cur] ++;
			break;
		}
	}
	int n = (int)s.size();

	long long ans = 0;
	for(int d = 0; d < n; d++){
		int nz = 0;
		for(int e = d+1; e < n; e++){
			if(s[e] != '0') nz++;
		}
		for(char v = '0'; v < s[d]; v++){
			// less digits
			int nzz = nz + (v != '0');
			if(nzz > k) continue;
			int need = k - nzz;
			long long cur = 1;
			for(int i = 0; i < need; i++) cur *= 9;
			for(int i = 0; i < need; i++){
				cur *= (d - i);
				cur /= (i + 1);
			}
			ans += cur;
		}
	}
	cout << ans << '\n';
}