#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
const int N=3009,mod=998244353;
int n,s,a[N],dp[N][N];
int f(int  i,int x){
	if(x and i==n)return 0;
	if(x<0)return 0;
	if(x==0)return 1+n-i;
	if(dp[i][x]!=-1)return dp[i][x];
	int res=f(i+1,x-a[i]);
	if(x==s)res=res*(i+1)%mod;
	res=(res+f(i+1,x))%mod;
	return dp[i][x]=res;
}
int32_t main(){
	if(fopen("input.txt", "r"))
	freopen("input.txt", "r", stdin),
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	memset(dp,-1,sizeof dp);
	cin >> n >> s;
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << f(0,s);
}