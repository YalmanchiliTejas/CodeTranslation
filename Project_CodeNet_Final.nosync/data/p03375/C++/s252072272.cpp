#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
ll f[N],g[N][N],pw[N];
ll n,mo,C[N][N];
void move(ll &a,ll b){a=(a+b)%mo;}
ll power(ll a,ll b){
	ll ans=1;
	while (b){
		if (b&1)ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}return ans;
}
int main(){
	cin>>n>>mo;
	g[0][0]=1;
	pw[0]=2;C[0][0]=1;
	for (int i=1;i<=n;i++){
		pw[i]=pw[i-1]*pw[i-1]%mo;
		g[i][0]=1;
		C[i][0]=C[i][i]=1;
		for (int j=1;j<=i;j++)
			move(g[i][j],g[i-1][j]*(j+1)+g[i-1][j-1]),
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	}
	ll ans=0;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=i;j++)
			move(f[i],g[i][j]*power(2,(n-i)*j));
		f[i]=f[i]*pw[n-i]%mo;
		move(ans,f[i]*C[n][i]*power(-1,i));
	}
	cout<<(ans%mo+mo)%mo<<endl;
}