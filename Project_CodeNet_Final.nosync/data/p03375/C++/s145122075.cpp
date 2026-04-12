#include<bits/stdc++.h>
using namespace std;
int n,M;
int f[3005],ans;
int S[3005][3005],C[3005][3005];

int ksm(int x,int y,int mod){
	int res=1;
	while(y){
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod,y/=2;
	}
	return res;
}

int main(){
	cin>>n>>M;
	C[0][0]=S[0][0]=1;
	for(int i=1;i<=n+1;i++){
		C[i][0]=1,S[i][0]=0;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
			S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j]%M)%M;
		}
	}
	for(int i=0;i<=n;i++){
		int add=ksm(2,ksm(2,n-i,M-1),M);
		int add1=1,add2=ksm(2,n-i,M);
		for(int j=1;j<=i+1;j++){
			(f[i]+=1ll*S[i+1][j]*add1%M*add%M)%=M;
			add1=1ll*add1*add2%M;
		}
		f[i]=1ll*f[i]*C[n][i]%M;
	}
	for(int i=0;i<=n;i++){
		if(i&1) (ans+=M-f[i])%=M;else (ans+=f[i])%=M;
	}
	printf("%d\n",ans);

	return 0;
}