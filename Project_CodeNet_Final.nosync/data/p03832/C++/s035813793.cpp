//wrong answer on test inf
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define ld long double
#define inf 1000000000
using namespace std;
#define N 1005
#define mod 1000000007
int n,a,b,c,d,f[N][N],C[N][N],w[N][N];
void upd(int &x,int y){ x+=y;x-=x>=mod?mod:0; }
int main(){
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	rep (i,0,n) C[i][0]=1;
	rep (i,1,n) rep (j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	rep (i,a,b){
		w[i][0]=1;
		for (int j=1;j<=d&&i*j<=n;j++) w[i][j]=(ll)w[i][j-1]*C[i*j-1][i-1]%mod;
	}
	int nk=0,k=1;f[0][0]=1;
	rep (t,a,b){//以每一种人数作为状态
		nk^=1,k^=1;memset(f[nk],0,sizeof(f[nk]));
		rep (i,0,n){
			upd(f[nk][i],f[k][i]);
			for (int j=c;j<=d&&i+j*t<=n;j++) upd(f[nk][i+j*t],(ll)f[k][i]*w[t][j]%mod*C[i+j*t][i]%mod);
		}
	}
	cout<<f[nk][n]<<endl;
	return 0;
}