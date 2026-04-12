#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

inline ll read(){
	ll x=0,w=1;char c=getchar();
	while(c<'0'||c>'9')w=c=='-'?-1:1,c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*w;
}

ll n,k,ans,t;

int main(){
	n=read(),k=read();
	for(int b=k+1;b<=n;++b){
		t=n/b-1;
		ans+=(b-k)*(t+1)+max(n-b*(t+1)-k+1,0ll);
	}
	if(k==0)ans-=n;
	printf("%lld",ans);
	
	return 0;
}