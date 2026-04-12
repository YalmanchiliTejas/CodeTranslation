#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define MAX ((ll)(1e17+100))
#define MX ((ll)(1e5+100))
#define ARRS ((ll)(1e6+100))
#define ARS ((ll)(1e3+100))
#define HS ((ll)(233))
#define MOD ((ll)(1e9+7))
#define EP ((double)(1e-9))
#define LG 21
#define mul(a,b) a=((a)*(b))%MOD
using namespace std;

ll dp[200][200][3];
ll a[ARRS];

ll pw(ll a,ll b){
	ll p=1;
	while(b){
		if(b&1)p=(p*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return p;
}

void go(ll l,ll r,ll d){
	if(l==r){
		dp[l][r][0]=1;
		dp[l][r][1]=1;
		dp[l][r][2]=0;
		return;
	}
	vector<ll> v;
	ll mn=MAX;
	for(int i=l; i<r; i++)
		mn=min(mn,a[i]);
	v.pb(l-1);
	for(int i=l; i<r; i++)
		if(a[i]==mn)v.pb(i);
	v.pb(r);
	for(int i=0; i<v.size()-1; i++)
		go(v[i]+1,v[i+1],mn);
	dp[l][r][0]=1;
	ll t=0;
	for(int i=0; i<v.size()-1; i++){
		mul(dp[l][r][0],dp[v[i]+1][v[i+1]][t]);
		t^=(v[i+1]-(v[i]+1));
		t^=1;
		t&=1;
	}
	dp[l][r][1]=1;
	t=1;
	for(int i=0; i<v.size()-1; i++){
		mul(dp[l][r][1],dp[v[i]+1][v[i+1]][t]);
		t^=(v[i+1]-(v[i]+1));
		t^=1;
		t&=1;
	}
	dp[l][r][2]=1;
	for(int i=0; i<v.size()-1; i++){
		if(v[i]+1!=v[i+1]){
			mul(dp[l][r][2],
				dp[v[i]+1][v[i+1]][0]+
				dp[v[i]+1][v[i+1]][1]+
				dp[v[i]+1][v[i+1]][2]);
			//cout<<v[i]+1<<" - "<<v[i+1]<<endl;
			
			//cout<<
				//dp[v[i]+1][v[i+1]][0]+
				//dp[v[i]+1][v[i+1]][1]+
				//dp[v[i]+1][v[i+1]][2]<<endl;
		}
		if(r!=v[i+1])
		mul(dp[l][r][2],2);
	}
	//cout<<dp[l][r][2]<<endl;
	dp[l][r][2]-=dp[l][r][0]+dp[l][r][1];
	dp[l][r][2]%=MOD;
	dp[l][r][2]+=MOD;
	dp[l][r][2]%=MOD;
	mul(dp[l][r][0],pw(2,mn-d));
	mul(dp[l][r][1],pw(2,mn-d));
	//cout<<l<<" "<<r-1<<" "<<dp[l][r][0]<<" = "<<dp[l][r][1]<<" "<<dp[l][r][2]<<endl;
}

int main(){
	ll n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	go(0,n,1);
	cout<<(dp[0][n][0]+dp[0][n][1]+dp[0][n][2])%MOD;
}
