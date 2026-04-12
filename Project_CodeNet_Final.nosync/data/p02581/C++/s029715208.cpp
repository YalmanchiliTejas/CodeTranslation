//start:9:48
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2005;
const int inf=1e9;
int dp[N][N],dp2[N][N],f[3*N],d[3*N],mx;
void Max(int &x,int &y,int z){x=y=max(x,z);}
void upd(int a,int b,int c){
	for (int i=1;i<=n;i++){
		Max(dp2[i][a],dp2[a][i],max(f[i],dp[i][b]+(b==c)));
	}
	Max(dp2[a][b],dp2[b][a],max(mx,dp[c][c]+1));
}
void come(int a){
	for (int i=1;i<=n;i++){
		Max(dp[a][i],dp[i][a],dp2[i][a]);
		f[i]=max(f[i],max(dp[a][i],dp[i][a]));
		mx=max(mx,f[i]);
	}
}
void work(int a,int b,int c){
//	cout << a << ' ' << b << ' ' << c << endl;
	upd(a,b,c);upd(b,c,a);upd(c,a,b);
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++) cout << dp2[i][j] << ' ';cout << endl;
//	}cout << endl;
	come(a);come(b);come(c);
	for (int i=1;i<=n;i++){
		dp2[i][a]=dp2[i][b]=dp2[i][c]=dp2[a][i]=dp2[b][i]=dp2[c][i]=-inf;
	}
}
int main(){
//	freopen("i.in","r",stdin);
	cin >> n;for (int i=1;i<=n*3;i++) cin >> d[i];
	memset(dp,-10,sizeof(dp));memset(dp2,-10,sizeof(dp2));memset(f,-10,sizeof(f));
	dp[d[1]][d[2]]=dp[d[2]][d[1]]=f[d[1]]=f[d[2]]=0;
	for (int i=1;i<n;i++){
		if (d[3*i]==d[3*i+1] && d[3*i+1]==d[3*i+2]) m++;
		else work(d[3*i],d[3*i+1],d[3*i+2]);
//		for (int j=1;j<=n;j++){
//			for (int k=1;k<=n;k++) cout << dp[j][k] << ' ';cout << endl;
//		}cout << endl;
	}
	Max(mx,dp[d[3*n]][d[3*n]],dp[d[3*n]][d[3*n]]+1);
	cout << mx+m << endl;
	return 0;
}