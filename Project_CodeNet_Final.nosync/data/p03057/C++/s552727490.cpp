#include<bits/stdc++.h>
#define ll long long
#define inf 1010000000
#define infll 1010000000000000000ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define ad(x,y) (x=(x+(y))%mod)
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define N 200009
using namespace std;

int n,m,dp[N][2][2],f[N]; char ch[N]; vi e;
void solve0(){
	int i,j,k,l; dp[1][0][0]=dp[1][1][1]=1;
	for (i=2; i<=n; i++)
		for (j=0; j<2; j++)
			for (k=0; k<2; k++)
				for (l=0; k+l<2; l++)
					ad(dp[i][j][l],dp[i-1][j][k]);
	printf("%d\n",((dp[n][0][0]+dp[n][0][1])%mod+dp[n][1][0])%mod);
}
int main(){
	scanf("%d%d%s",&n,&m,ch+1);
	int i;
	if (ch[1]=='B')
		for (i=1; i<=m; i++)  ch[i]=(ch[i]=='R'?'B':'R');
	for (i=2; i<=m; i++) if (ch[i]=='B') break;
	if (i>m){
		solve0(); return 0;			
	}
	memset(dp,0,sizeof(dp));
	for (i=m; i; i--) if (ch[i]=='B') break;
	int lim=n,now=0;
	for (; i>=0; i--){
		if (!i || ch[i]=='B'){
			if (now) e.pb(now);
			now=0;
		} else now++;
	}
	reverse(e.begin(),e.end());
	for (i=0; i<e.size(); i++){
		if (i==0 && !(e[i]&1)) dn(lim,e[i]+2);
		if (e[i]&1) dn(lim,e[i]+1);	
	}
	f[0]=f[2]=1;
	for (i=3; i<=n; i++)
		f[i]=((ll)f[i-2]-(i-2-lim>=0?f[i-2-lim]:0)+f[i-2]+mod)%mod;
	int ans=0;
	for (i=2; i<=lim; i+=2) ad(ans,(ll)f[n-i]*i);
	printf("%d\n",ans);
	return 0;
}
