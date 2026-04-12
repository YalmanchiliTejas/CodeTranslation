#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int Mod=(1e9)+7;
const int maxn=(1e4)+10;
int n,mod;
char s[maxn];
int dp[maxn][110][2];
void update(int &x,int y) {
	x+=y; if (x>=Mod) x-=Mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	read(mod);
	dp[0][0][1]=1;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<mod;j++) {
			for (int op=0;op<2;op++) {
				if (!dp[i][j][op]) continue;
			//	printf("%d %d %d %d\n",i,j,op,dp[i][j][op]);
				for (int k=0;k<=9;k++) {
					if (op&&k>s[i+1]-'0') break;
					update(dp[i+1][(j+k)%mod][op&&(k==s[i+1]-'0')],dp[i][j][op]);
				}
			}	
		}
	}
	printf("%d\n",((ll)dp[n][0][0]+dp[n][0][1]+Mod-1)%Mod);
	return 0;
}