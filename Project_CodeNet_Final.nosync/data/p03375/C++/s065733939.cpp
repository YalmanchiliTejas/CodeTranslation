#include<bits/stdc++.h>
#define ll long long
#define re register
#define ull unsigned ll
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*t;
}
const int N=3005;
int n,P,Ans;
int f0[N],f1[N],C[N][N],S[N][N];
int Mod(int x){return x>=P?x-P:x;}
int ksm(int x,int k){
	int res=1;
	while(k){
		if(k&1)res=1ll*res*x%P;
		x=1ll*x*x%P,k>>=1;
	}return res;
}
void Pre(int n){
	f0[0]=1;for(int i=1;i<=n;i++)f0[i]=2ll*f0[i-1]%P;
	f1[0]=1;for(int i=1;i<=n;i++)f1[i]=2ll*f1[i-1]%(P-1);
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	}S[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)S[i][j]=Mod(S[i-1][j-1]+1ll*S[i-1][j]*j%P);
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),P=read(),Pre(n+1);
	for(int i=0;i<=n;i++){
		int res=0;
		for(int j=0;j<=i;j++)res=Mod(res+1ll*S[i+1][j+1]*ksm(f0[n-i],j)%P);
		Ans=Mod(Ans+1ll*res*(i&1?P-1:1)%P*C[n][i]%P*ksm(2,f1[n-i])%P);
	}printf("%d",Ans);
	return 0;
}