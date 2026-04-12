#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f;
const double pi=3.1415926535897932384626;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int maxn=1e5+5;
ll n,x,m,now,cnt,l,r,ans,idx[maxn],sum[maxn];
int main(){
	n=read(),x=read(),m=read();
	for(cnt=1,now=x;;now=now*now%m,cnt++){
		if(!idx[now]) idx[now]=cnt;
		else{
			l=idx[now];
			r=cnt-1;
			break;
		}
		sum[cnt]=sum[cnt-1]+now;
	}
	ll len=r-l+1;
	ans+=sum[min(n,l-1)];
	n=max(0ll,n-l+1);
	if(n) ans+=(sum[r]-sum[l-1])*(n/len)+sum[n%len+l-1]-sum[l-1];
	printf("%lld\n",ans);
	return 0;
}