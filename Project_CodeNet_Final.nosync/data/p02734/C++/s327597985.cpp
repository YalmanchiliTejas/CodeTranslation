// i hope i get better                                                           
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int sz=3e3+9;
int n,k;
int a[sz];
ll dp[sz][sz][2][2];
ll m=998244353;
ll add(ll a,ll b){return (a%m+b%m)%m;}
ll mul(ll a,ll b){return (a%m*b%m)%m;}

ll solve(int idx,int rem,int st,int en){
	ll &ret=dp[idx][rem][st][en];
	if(~ret) return ret;
	if(st&&en){
		return !rem;
	}
	if(!idx) return 0;
	ret=solve(idx-1,rem,st,en);
	if(!en){
		ret=add(ret,solve(idx-1,rem,st,1));
		if(a[idx]<=rem){
			ret=add(ret,solve(idx-1,rem-a[idx],st,1));
			ret=add(ret,solve(idx-1,rem-a[idx],1,1));
		}
	}else{
		ret=add(ret,solve(idx-1,rem,1,1));
		if(a[idx]<=rem){
			ret=add(ret,solve(idx-1,rem-a[idx],st,en));
			ret=add(ret,solve(idx-1,rem-a[idx],1,en));
		}
	}
	return ret;
}


int main(){
	cin>>n>>k;
	for(int i=1; i <=n; ++i){
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(n,k,0,0);
    return 0;
}