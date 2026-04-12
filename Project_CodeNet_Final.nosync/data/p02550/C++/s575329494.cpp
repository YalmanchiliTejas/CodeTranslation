#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll sum[114514],a[114514];
ll f[114514];
int main(){
	ll n,x,m;
	cin>>n>>x>>m;
	a[1]=x;
	sum[1]=x;
	f[x]=1;
	ll ans=x;
	for(int i=2;i<=min(n,m+1);i++){
		a[i]=a[i-1]*a[i-1]%m;
		sum[i]=a[i]+sum[i-1];
		if(f[a[i]]){
			ans=sum[i-1];
			//cout<<sum[i-1]<<' '<<sum[f[a[i]]-1];
			ll x=n+1-i;
			ans+=(x/(i-f[a[i]]))*(sum[i-1]-sum[f[a[i]]-1])+sum[f[a[i]]+x%(i-f[a[i]])-1]-sum[f[a[i]]-1];
			break;
		}else{
			f[a[i]]=i;
			ans=sum[i];
		}
	}
	cout<<ans;
	return 0;
}
