#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll d,mod = 1000000007;
ll dp[10009][109][9];
string s;
ll bt(ll id,ll sum,ll t){
	if(id == s.size()) return (sum%d==0);
	ll &ret = dp[id][sum][t];
	if(ret != -1) return ret;
	ret = 0;
	if(t == 1){
		for(int i=0;i<=9;i++){
			ret = (ret + bt(id+1,(sum+i)%d,1)) % mod;
		}
	}
	else{
		ll n = s[id] - '0';
		for(int i=0;i<n;i++){
			ret = (ret + bt(id+1,(sum+i)%d,1)) % mod;
		}
		ret = (ret + bt(id+1,(sum+n)%d,0)) % mod;
	}
	return ret;
}
int main(){
	cin>>s>>d;
	memset(dp,-1,sizeof(dp));
	cout<<(bt(0,0,0)+mod-1)%mod<<endl;
}
