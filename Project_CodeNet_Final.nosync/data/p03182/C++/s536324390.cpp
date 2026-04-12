#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,m,b[800005],c[800005];
vector<pair<ll,ll> > a[800005];
void f(ll x,ll l,ll r,ll rl,ll rr,ll z){
    if(rl<=l and r<=rr){
        b[x]+=z,c[x]+=z;
        return ;
    }
	ll mid=(l+r)>>1;
	if(rl<=mid)f(x*2,l,mid,rl,rr,z);
	if(rr>mid)f(x*2+1,mid+1,r,rl,rr,z);
	b[x]=max(b[x*2],b[x*2+1])+c[x];
}
int main(){
	n=read(),m=read();
	for(int i=0;i<m;i++){
		ll x=read(),y=read(),z=read();
		a[y].push_back({x,z});
	}
	for(int i=1;i<=n;i++){
        f(1,1,n,i,i,b[1]);
        for(int j=0;j<a[i].size();j++)
            f(1,1,n,a[i][j].first,i,a[i][j].second);
    }
    printf("%lld",max(0ll,b[1]));
	return 0;
}