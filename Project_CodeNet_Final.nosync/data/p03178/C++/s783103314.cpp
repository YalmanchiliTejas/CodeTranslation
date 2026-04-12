#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
const ll nax = 1e4+7;

ll dp[nax][102][2];
string num;
ll d;

ll di(ll pos,ll sum,int f){
	if (pos==num.size()) {
		if (sum==0) return 1;
		return 0;
	}
	
	if (dp[pos][sum][f]!=-1) return dp[pos][sum][f];
	
	ll res=0,nf,lim;
	
	if (f==0) lim=(num[pos]-'0');
	else lim=9;
	
	for (ll i=0;i<=lim;++i){
		
		nf=f;
		
		if (i<lim) nf=1;
		
		res=(res+di(pos+1,(sum+i)%d,nf))%mod;
	}
	
	return dp[pos][sum][f]=res;
	
}

int main(){
//	freopen("input.inp","r",stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp,-1,sizeof(dp));
	cin>>num>>d;
	
//	cout<<num<<" "<<d<<"\n";
	
	ll res=(di(0,0,0)-1+mod)%mod;
	
/*	for (ll i=0;i<=num.size();++i){
		for (ll j=0;j<d;++j){
			for (ll f=0;f<2;++f) cout<<dp[i][j][f]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";*/
	
	cout<<res<<"\n";
}