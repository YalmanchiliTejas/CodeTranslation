#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T f=0,x=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
namespace run{
	const int N=3009;
	int mod;
	inline int add(int x,int y){return x+y>=mod?x-mod+y:x+y;}
	inline int sub(int x,int y){return x>=y?x-y:x+mod-y;}
	inline int qpow(int x,int y,int _mod=mod){
		int ret=1;
		while(y){
			if(y&1) ret=1LL*x*ret%_mod;
			x=1LL*x*x%_mod,y>>=1;
		}
		return ret;
	}

	int n,pw[N*N],S[N][N],C[N][N];
	int main(){
		n=read<int>(),mod=read<int>();

		C[0][0]=1;
		for(int i=1;i<=n+1;i++){
			C[i][0]=1;
			for(int j=1;j<=i;j++)
				C[i][j]=add(C[i-1][j-1],C[i-1][j]);
		}
		S[0][0]=1;
		for(int i=1;i<=n+1;i++){
			S[0][i]=0;
			for(int j=1;j<=i;j++)
				S[i][j]=(1LL*S[i-1][j]*j+S[i-1][j-1])%mod;
		}

		pw[0]=1;
		for(int i=1;i<=n*n;i++) pw[i]=2LL*pw[i-1]%mod;

		int ans=0;
		for(int i=0;i<=n;i++){
			int ret=0;
			for(int j=0;j<=i;j++)
				ret=(1LL*S[i+1][j+1]*pw[(n-i)*j]+ret)%mod;
			ret=1LL*ret*qpow(2,qpow(2,n-i,mod-1))%mod;
			if(i&1) ans=sub(ans,1LL*C[n][i]*ret%mod);
			else ans=add(ans,1LL*C[n][i]*ret%mod);
		}
		printf("%d\n",ans);
		return 0;
	}
}
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}