#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
const int N=109;
int k,n;
string st;
int dp[N][4][2];
int solve(int i,int x,int f){
	if(x<0 or i>n)return 0;
	if(i==n){
		if(x==0)return 1;
		else return 0;
	}
	if(dp[i][x][f]!=-1)return dp[i][x][f];
	int sum=0,m=10;
	if(f)m=st[i]-'0';
	for(int j=0;j<m;j++){
		sum+=solve(i+1,x-(j!=0),0);
	}
	if(f){
		sum+=solve(i+1,x-(m!=0),1);
	}
	return dp[i][x][f]=sum;
}
int32_t main(){
	if(fopen("input.txt", "r"))
		freopen("input.txt", "r", stdin),
		freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> st;
	cin >> k;
	n=st.size();
	memset(dp,-1,sizeof dp);
	// cout << k << endl;
	cout << solve(0,k,1);
}