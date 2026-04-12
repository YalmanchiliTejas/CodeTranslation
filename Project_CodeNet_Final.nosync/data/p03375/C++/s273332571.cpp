//#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int n,m;
int f[maxn],invf[maxn];
int S[maxn][maxn];
inline int ksm(int x,int y,int MOD){
	int ans=1;
	while(y){
		if(y&1) ans=(1ll*ans*x)%MOD;
		x=(1ll*x*x)%MOD; y>>=1; 
	}
	return ans;
}
int ans=0;
inline int C(int x,int y){
	if(x<y) return 0;
	return 1ll*f[x]*invf[y]%m*invf[x-y]%m; 
}
int main(){
	scanf("%d%d",&n,&m);
	f[0]=1; for(int i=1;i<=n;i++) f[i]=1ll*f[i-1]*i%m;
	invf[0]=1; invf[n]=ksm(f[n],m-2,m);
	for(int i=n-1;i>=1;i--) invf[i]=1ll*invf[i+1]*(i+1)%m;
	S[0][0]=1; S[1][1]=1; S[1][0]=0;
	for(int i=0;i<=n;i++){
		int res=0;
		for(int k=0;k<=i;k++){
			int tmp=1;
			if(!S[i+1][k+1]) S[i+1][k+1]=(S[i][k]+1ll*(k+1)*S[i][k+1]%m)%m;
//			cout<<i+1<<' '<<k+1<<' '<<S[i+1][k+1]<<endl; 
			tmp=1ll*S[i+1][k+1]*ksm(2,(n-i)*k,m)%m;
			tmp=1ll*tmp*ksm(2,ksm(2,n-i,m-1),m)%m;
			res=(res+tmp)%m;
		}
		res=(1ll*res*C(n,i))%m;
//		cout<<res<<endl;
		if(i&1) ans=(ans-res+m)%m;
		else ans=(ans+res)%m;
	}
	printf("%d\n",ans);
	return 0;
} 