#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=3030;
int n,P,w,x,r,ans,c[N][N],s[N][N],pp[N],pw[N];
void ini(int n){
	FOR(i,0,n) c[i][0]=1;
	s[0][0]=pw[0]=1;pp[0]=2;
	FOR(i,1,n)FOR(j,1,i){
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
		s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%P;
	}
	FOR(i,1,n) pw[i]=(pw[i-1]<<1)%P;
	FOR(i,1,n) pp[i]=1ll*pp[i-1]*pp[i-1]%P;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&P);ini(n+1);
	FOR(i,0,n){
		w=1ll*(i&1?P-1:1)*c[n][i]%P;x=0;r=1;
		FOR(j,0,i) (x+=1ll*s[i+1][j+1]*pp[n-i]%P*r%P)%=P,r=1ll*r*pw[n-i]%P;
		(ans+=1ll*w*x%P)%=P;
	}
	cout<<ans<<'\n';
}