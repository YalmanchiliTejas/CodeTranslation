#include<bits/stdc++.h>
#define ll long long
#define N 3010
using namespace std;
ll po(ll x,ll y,ll mo){ll z=1;while (y){if (y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
ll ans,n,mo,f[N][N],c[N][N],p[N*N];
int main(){
	cin>>n>>mo;
	f[0][0]=c[0][0]=1;
	p[0]=1;for (int i=1;i<=n*n;i++)p[i]=p[i-1]*2%mo;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++){
			f[i][j]=f[i-1][j]*(1+j)%mo;c[i][j]=c[i-1][j];
			if (j)f[i][j]=(f[i][j]+f[i-1][j-1])%mo,c[i][j]=(c[i][j]+c[i-1][j-1])%mo;
		}
	for (int i=0;i<=n;i++){
		ll su=0;
		for (int j=0;j<=i;j++)su=(su+p[(n-i)*j]*f[i][j])%mo;
		ans=(ans+((po(mo-1,i,mo)*po(2,po(2,n-i,mo-1),mo)%mo)*su%mo)*c[n][i])%mo;
	}
	cout<<ans<<endl;
	return 0;
}