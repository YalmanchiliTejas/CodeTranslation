#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=3e3+10;
int ksm(int x,int y,int mod){
	int res=1;
	while(y){
		if(y&1) res=(ll)x*res%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return res;
}
int C[maxn][maxn],S[maxn][maxn];
int main(){
	int n=read(),mod=read();
	S[0][0]=C[0][0]=1;
	REP(i,1,n+1){
		C[i][0]=1;S[i][0]=0;
		REP(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod,S[i][j]=(S[i-1][j-1]+(ll)j*S[i-1][j]%mod)%mod;
	}
	int ans=0;
	REP(i,0,n){
		int tmp=0,res=1,num=ksm(2,n-i,mod);
		REP(j,0,i){
			tmp=(tmp+(ll)res*S[i+1][j+1]%mod)%mod;
			res=(ll)res*num%mod;
		}
		tmp=(ll)tmp*C[n][i]%mod*ksm(2,ksm(2,n-i,mod-1),mod)%mod;
		ans=(ans+((i&1)?(mod-tmp):tmp))%mod;
	}
	printf("%d\n",ans);
	return 0;
}
