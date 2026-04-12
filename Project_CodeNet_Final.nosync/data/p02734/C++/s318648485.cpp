//by szh
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define SZ(x) (int((x).size()))
#define se second
#define ll long long
#define pq priority_queue
#define MP make_pair
#define pii pair<int,int>
#define mod 998244353
#define debug(x) cerr<<#x<<"="<<x<<'\n'

const int maxn=3010;

int n,s;
int a[maxn];
int f[maxn][maxn][2];
ll ans=0;

int main(){
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=s;j++) {
			f[i][j][0]=f[i-1][j][0];
			if (j>=a[i]) f[i][j][1]=f[i-1][j-a[i]][0];
			if (j==a[i]) f[i][j][1]=((ll)f[i][j][1]+(ll)i)%mod;
			(f[i][j][0]+=f[i][j][1])%=mod;
			if (j==s) ans=((ll)ans+(ll)f[i][j][1]*(ll)(n-i+1))%mod;
		}
	printf("%d",ans);
	return 0;
}
