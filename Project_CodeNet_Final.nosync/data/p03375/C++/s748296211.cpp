#include<bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
    int x=0,p=1;char c=getchar();
    while (c<=32)c=getchar();
    if(c==45)p=-p,c=getchar();
    while (c>32)x=x*10+c-48,c=getchar();
    return x*p;
}
using namespace std;
//ruogu
const int N=3010;
int n,mod,res,p[N],pw[N*N],C[N][N],S[N][N];
//
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
inline void sub(int &x,int y){x-=y;if(x<0)x+=mod;}
inline int mul(int x,int y){ll ans=1ll*x*y;return ans%mod;}
inline int modpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int main(){
	n=getint();mod=getint();
	pw[0]=1;
	for(int i=1;i<N*N;i++){
		pw[i]=pw[i-1];
		add(pw[i],pw[i]);
	}
	rep(i,N){
		--mod;
		int tmp=modpow(2,i);
		++mod;
		p[i]=modpow(2,tmp);	
	}
	rep(i,N)C[i][0]=1;
	for(int i=1;i<N;i++)for(int j=1;j<=i;j++){
		C[i][j]=C[i-1][j];
		add(C[i][j],C[i-1][j-1]);
	}
	S[0][0]=1;
	for(int i=1;i<N;i++)for(int j=1;j<=i;j++){
		if(j)S[i][j]=S[i-1][j-1];
		add(S[i][j],mul(j,S[i-1][j]));
	}
	rep(i,n+1){
		int tmp=0;
		rep(j,i+1)add(tmp,mul(pw[(n-i)*j],S[i+1][j+1]));
		tmp=mul(tmp,mul(C[n][i],p[n-i]));
		if(i&1)sub(res,tmp);
		else add(res,tmp);
	}
	cout<<res<<endl;
	return 0;
}
