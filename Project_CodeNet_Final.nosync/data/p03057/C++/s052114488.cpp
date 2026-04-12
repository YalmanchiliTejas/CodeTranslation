#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=200005;
const int mo=1000000007;
int n,m;
char s[N];
namespace solver1{
	int f[N][2][2];
	void solve(){
		f[1][0][0]=f[1][1][1]=1;
		For(i,2,n) For(j,0,1) For(k,0,1) For(l,0,1)
			if (k|l) f[i][j][l]=(f[i][j][l]+f[i-1][j][k])%mo;
		int ans=0;
		For(i,0,1) For(j,0,1)
			if (i|j) ans=(ans+f[n][i][j])%mo;
		printf("%d\n",ans);
	}
}
namespace solver2{
	int pre[N],mn;
	int g[N],h[N];
	void solve(){
		pre[1]=1;
		mn=1<<30;
		For(i,2,m)
			pre[i]=(s[i]==s[i-1]?pre[i-1]+1:1);
		For(i,2,m)
			if (s[i-1]=='R'&&s[i]!='R'){
				if (pre[i-1]==i-1){
					if ((i-1)%2==0) mn=min(mn,pre[i-1]+1);
					else mn=min(mn,pre[i-1]);
				}
				else if (pre[i-1]%2)
					mn=min(mn,pre[i-1]);
			}
		++mn;
		//printf("%d\n",mn);
		g[0]=h[0]=1;
		For(i,1,n){
			g[i]=((i>=2?h[i-2]:0)+mo-(i>=mn+2?h[i-mn-2]:0))%mo;
			h[i]=(g[i]+(i>=2?h[i-2]:0))%mo;
			//printf("%d %d\n",g[i],h[i]);
		}
		int ans=0;
		for (int i=2;i<=n&&i<=mn;i+=2)
			ans=(ans+1ll*i*g[n-i])%mo;
		printf("%d\n",ans);
	}
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	if (s[1]=='B'){
		For(i,1,m)
			if (s[i]=='B') s[i]='R';
			else s[i]='B';
	}
	bool flag=0;
	For(i,1,m)
		if (s[i]!=s[1])
			flag=1;
	if (!flag)
		solver1::solve();
	else solver2::solve();
} 
