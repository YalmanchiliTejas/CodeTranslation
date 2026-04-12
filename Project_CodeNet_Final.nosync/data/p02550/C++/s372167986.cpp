#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
inline ll r() {
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
#define d r()
ll n,m,x,ans,kkk;
ll a[100010],re,li;
bool fl[100010];
ll mul(ll a,ll b){
	ll ans=0;
	while(b){
		if(b&1)ans=ans+a;
		a=a+a;
		b/=2;
	}
	return ans;
}
int main(){
	n=d,x=d,m=d;
	a[1]=x%m,fl[a[1]]=1,fl[0]=1;
	f(i,2,2*m){
		a[i]=a[i-1]*a[i-1]%m;
		if(fl[a[i]]){re=i;break;}
		fl[a[i]]=1;
	}
	if(a[re]==0){
		ll tmp=x,ans=x;
		f(i,2,n){
			tmp=tmp*tmp%m;
			ans+=tmp;
			if(tmp==0)break;
		}
		printf("%lld",ans);
		return 0;
	}
	f(i,1,re)
		if(a[re]==a[i]){
			re--;
			li=i;
			break;
		}
	f(i,li,re)kkk+=a[i];
	for(int i=1;i<=li-1;i++)ans+=a[i];
	n-=(li-1);
	ans=ans+mul(kkk,n/(re-li+1)),n%=(re-li+1);
	if(n)for(int i=li;i<=li+n-1;i++)ans+=a[i];
	printf("%lld",ans);
	return 0;
}
