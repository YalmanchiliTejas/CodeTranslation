 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
string s;
ll a[500][500];
void init() {
	a[0][0] = 1;
	for (int i = 1; i <= 101; i++) {
		a[i][0] = 1;
		for (int j = 1; j <=101; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
}
ll dfs(string s1, int k1) {
	int n = s1.length();
 if(k1==0) return 1;
	//if(s1[0]=='9') return pow(9,k1)*a[n][k1];
	if(n==1) return s1[0]-'0';
	string s2=s1.substr(1,n-1);
	if(s1[0]=='0') return dfs(s2,k1);
	//ll d = n - 1;
	ll c = pow(9,k1);
	ll ans =a[n-1][k1] * c;
	ll t = s1[0] - '0' - 1;
	ll d=pow(9,k1-1);
	ans = ans + t * a[n-1][k1-1]*d ;
	return ans+dfs(s2,k1-1);
}
	int main() {
		cin >> s >> k;
		init();
		if (k > s.length()) cout << 0 << '\n';
		else
	cout << dfs(s, k);
}
