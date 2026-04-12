#include<bits/stdc++.h>
using namespace std;
int n,a[55][30];
string s,ans;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		for(int j = 0; j < s.size(); j++)
			a[i][s[j] - 97]++;
	}
	for(int i = 0; i < 26; i++) {
		int num = 2147483647;
		for(int j = 1; j <= n; j++)
			num = min(num,a[j][i]);
		for(int j = 0; j < num; j++)
			ans += char(i + 97);
	}
	cout << ans << endl;
	return 0;
}