#include<bits/stdc++.h>
#define ls ch[x][0]
#define rs ch[x][1]
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

const ll mod=1e9+7;
ll n,a[200010],sum,ans;

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		ans=(ans+a[i]*sum%mod)%mod;
		sum=(sum+a[i])%mod;
	}
	cout<<ans;
	return 0;
}
