#include<cstdio>
using namespace std;

int N,M,Ans;
int C[3005][3005],S[3005][3005];

int Pow(int base,int n,int mod){
	int ans=1;
	for(;n;n>>=1){
		if(n&1)
			ans=1ll*ans*base%mod;
		base=1ll*base*base%mod;
	}
	return ans;
}

int main(){
	int i,j,x;
	scanf("%d%d",&N,&M);
	for(i=0;i<=N;i++){
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=M)
				C[i][j]-=M;
		}
	}
	S[0][0]=1;
	for(i=1;i<=N+1;i++)
		for(j=1;j<=i;j++){
			S[i][j]=S[i-1][j-1]+1ll*j*S[i-1][j]%M;
			if(S[i][j]>=M)
				S[i][j]-=M;
		}
	for(i=0;i<=N;i++){
		for(x=j=0;j<=i;j++){
			x+=1ll*S[i+1][j+1]*Pow(2,(N-i)*j,M)%M;
			if(x>=M)
				x-=M;
		}
		x=1ll*x*C[N][i]%M*Pow(2,Pow(2,N-i,M-1),M)%M;
		if(i&1)
			x=(M-x)%M;
		Ans+=x;
		if(Ans>=M)
			Ans-=M;
	}
	printf("%d\n",Ans);
	return 0;
}