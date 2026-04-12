#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
string s;
ll f[1010][5],g[1010][5];
int main()
{
	cin>>s;
	int n = s.length();
	ll ans = 0;
	int k;cin>>k;
	if(k==1)ans += 9*(n-1);
	if(k==2){
		for(int i=2;i<n;i++)
			ans += 9*(i-1)*9;
	}
	if(k==3){
		for(int i=3;i<n;i++)
			ans += 9*9*9*(i-1)*(i-2)/2;
	}
//	cout << ans << endl;
	f[0][1] = 1;
	g[0][1] = s[0]-'1';
	for(int i=1;i<n;i++)
	for(int j=1;j<=k;j++){
		if(s[i]=='0'){
			f[i][j] = f[i-1][j];
			g[i][j] = g[i-1][j] + g[i-1][j-1]*9;
		}
		else{
			f[i][j] = f[i-1][j-1];
			g[i][j] = g[i-1][j] + f[i-1][j] + f[i-1][j-1]*(s[i]-'1') + g[i-1][j-1]*9;
		}
	}
//	cout<<"!"<<g[n-1][k]<<" "<<f[n-1][k]<<endl;
	ans += g[n-1][k]+f[n-1][k];
	cout << ans << endl; 
}
