#include<bits/stdc++.h>
#define maxn 3005
#define rep(i,j,k) for(int i=(j),LIM=(k);i<=LIM;i++)
#define per(i,j,k) for(int i=(j),LIM=(k);i>=LIM;i--)
using namespace std;

int n,P,S[maxn][maxn],C[maxn][maxn],pw[maxn];
int upd(int x){ return x += x >> 31 & P; }
int main(){
	scanf("%d%d",&n,&P);
	rep(i,S[0][0]=C[0][0]=1,n) rep(j,C[i][0]=1,i) C[i][j] = upd(C[i-1][j-1] + C[i-1][j] - P) % P;
	rep(i,1,n) rep(j,S[i][0]=1,i) S[i][j] = (S[i-1][j] * (j+1ll) + S[i-1][j-1]) % P;
	int ans = 0 , ppw = 2;
	rep(i,0,n) pw[i] = 1;
	per(k,n,0){
		int sm = 0;
		rep(i,0,k) sm = (sm + 1ll * S[k][i] * pw[i]) % P;
		ans = (ans + (k&1?-1ll:1ll)*C[n][k]*ppw%P*sm)%P;
		int p2 = 1;
		rep(i,0,n) pw[i] = 1ll * p2 * pw[i] % P , p2 = 2ll * p2 % P;
		ppw = ppw * 1ll * ppw % P;
	}
	printf("%d\n",(ans+P)%P);
}