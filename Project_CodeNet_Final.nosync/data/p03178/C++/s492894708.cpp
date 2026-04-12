#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mod = (int)1e9+7;

string k;
int n;
int d;
ll dp[10004][101][2];

ll solve(int i,int r, int flag){
	if(i==n){
		if(r)
			return 0;
		return 1;	
	}
	if(dp[i][r][flag]!=-1)
		return dp[i][r][flag];
		
	int digit = k[i]-'0';
	ll ans = 0;
	if(flag){
		for(int j=0;j<digit;j++){
			ans = (ans + solve(i + 1,(r  + j) % d,0)) % mod;
		}	
		ans = (ans + solve(i + 1,(r + digit) % d,1)) % mod;
	}
	else{
		for(int j=0;j<10;j++){
			ans = (ans + solve(i + 1,(r + j) % d,0))%mod;
		}
	}
	return dp[i][r][flag] = ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>k;
	cin>>d;
	n = k.length();
	memset(dp,-1,sizeof(dp));
	cout<<(solve(0,0,1)-1+mod)%mod;
	return 0;
}







