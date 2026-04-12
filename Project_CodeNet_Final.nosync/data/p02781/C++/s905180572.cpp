#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 205;

string s;
int t, n, a[N];
LL f[N][11][5], ans;

int main() {
	cin>>s>>t;
	n = s.size();
	for(int i = 1; i <= n; i++)
	   a[i] = s[i - 1] - '0';
	if(n == 1) {
		if(a[1] && t == 1) cout<<a[1]<<endl;
		else cout<<0<<endl;
		return 0;
	}
	f[1][0][0] = 1;
	for(int i = 1; i <= 9; i++)
	   f[1][i][1] = 1;
	for(int i = 2; i <= n; i++)
	   for(int j = 0; j <= 9; j++)
	      for(int k = 0; k <= 9; k++) {
	      	int cnt = (j != 0) + (k != 0);
	      	for(int p = cnt; p <= t; p++)
	      	   f[i][j][p] += f[i - 1][k][p - (j != 0)];
	      }
	for(int i = 1; i < n; i++)
	   for(int j = 1; j <= 9; j++)
	      ans += f[i][j][t];
	for(int i = 1; i < a[1]; i++)
	   ans += f[n][i][t];
	int res = t - 1;
	for(int i = 2; i <= n; i++) {
		if(res == -1) break;
		if(res != 0)
		for(int j = 0; j < a[i]; j++)
		   ans += f[n - i + 1][j][res];
		else if (a[i] != 0)
		   ans += f[n - i + 1][0][res];
		if(i == n) {
			if(res == 0 && a[i] == 0) ans += f[1][a[i]][res];
			if(res == 1 && a[i] != 0) ans += f[1][a[i]][res];
		} 
		if(a[i]) res--;
	}
	cout<<ans<<endl;
}
