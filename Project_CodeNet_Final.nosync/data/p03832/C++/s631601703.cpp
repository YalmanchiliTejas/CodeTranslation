#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e9+7;
ll n,A,B,C,D,i,j,k,ans,f[2010][2010],jc[2010],ny[2010];
ll ksm(ll x,ll y){
	ll xlh=1;
	while(y){
		if(y&1)xlh=xlh*x%p;
		x=x*x%p;
		y/=2;
	}
	return xlh;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&A,&B,&C,&D);
	jc[0]=ny[0]=1;
	for(i=1;i<=n;i++)jc[i]=jc[i-1]*i%p,ny[i]=ksm(jc[i],p-2)%p;
	f[0][A-1]=1;
	 for(j=A;j<=B;j++)
	  for(i=0;i<=n;i++){
	 	f[i][j]=f[i][j-1];
	 	for(k=C;k<=D&&i>=j*k;k++){
	 		f[i][j]=(f[i][j]+f[i-j*k][j-1]*jc[n-i+j*k]%p*ny[j*k]%p*ny[n-i]%p*jc[j*k]%p*ny[k]%p*ksm(ny[j],k)%p)%p;
	 	}
	 	//printf("%lld %lld %lld\n",j,i,f[i][j]);
	 }
	//for(i=A;i<=B;i++)ans=(ans+f[n][i])%p;
	printf("%lld",f[n][B]);
}