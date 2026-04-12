#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 3e5+10;
const int mod =   1e9+7;

string s;int d,dp[10005][2][105];
ll ans=0;


int main () {

	cin>>s>>d;
	dp[0][0][0]=1;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<2;j++){
			int x=j?9:s[i]-'0';
			for(int k=0;k<=x;k++){
				for(int l=0;l<d;l++){
					(dp[i+1][j|(k<x)][(k+l)%d]+=dp[i][j][l])%=mod;
				}
			}
		}
	}
	  cout<<(dp[s.size()][0][0]+dp[s.size()][1][0]-1ll+mod)%mod;
    return 0;
}