#include<bits/stdc++.h>
#define ll long long
#define p 998244353
using namespace std;
int jc[10000010],njc[10000010],inv[10000010],n,mi[10000010];
int C(int x,int y){
	return 1ll*jc[x]*njc[y]%p*njc[x-y]%p;
}
int main(){
	for(int i=0;i<2;i++)jc[i]=njc[i]=inv[i]=1;
	int n;cin>>n;
	mi[0]=1;mi[1]=2;
	for(int i=2;i<=n;i++){
		jc[i]=1ll*jc[i-1]*i%p;
		inv[i]=1ll*inv[p%i]*(p-p/i)%p;
		njc[i]=1ll*njc[i-1]*inv[i]%p;
		mi[i]=1ll*mi[i-1]*2%p;
	}
	int ans=1;
	for(int i=1;i<=n;i++)ans=1ll*ans*3%p;
	for(int i=n/2+1;i<=n;i++){
		(ans-=2ll*C(n,i)*mi[n-i]%p)%=p;
	}
	cout<<(ans+p)%p;
	return 0;
}
