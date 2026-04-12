/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=200005;
const int mod=1e9+7;
int n,m,mn,ans;
char s[maxn],ch;
int f[maxn],sum[maxn],g[maxn][2];

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d%d%s",&n,&m,s);
	ch=s[0];
	int cnt=0;
	mn=INF;
	bool fir=true;
	rep(i,m){
		if(s[i]!=ch){
			if(!cnt)continue;
			if(fir){
				if(cnt%2==0)cnt++;
				mn=min(mn,cnt);
			}
			else{
				if(cnt&1)mn=min(mn,cnt);
			}
			cnt=0;	
			fir=false;
		}
		else cnt++;
	}
	if(mn==INF){
		g[1][0]=1;
		for(int i=2;i<=n;i++){
			g[i][0]=(g[i-1][0]+g[i-1][1])%mod;
			g[i][1]=g[i-1][0];
		}
		ans=(g[n][0]+g[n][1])%mod;
		REP(i,n)g[i][0]=g[i][1]=0;
		g[1][1]=1;
		for(int i=2;i<=n;i++){
			g[i][0]=(g[i-1][0]+g[i-1][1])%mod;
			g[i][1]=g[i-1][0];
		}
		ans=(ans+g[n][0])%mod;
	}
	else{
		if(n&1)ans=0;
		else{
			n/=2;
			mn=(mn+1)/2;
			f[0]=1;sum[0]=1;
			REP(i,n){
				f[i]=(sum[i-1]-(i-mn-1>=0?sum[i-mn-1]:0)+mod)%mod;
				sum[i]=(sum[i-1]+f[i])%mod;
			}
			rep(i,n)if(n-i<=mn)ans=(ans+2LL*(n-i)*f[i]%mod)%mod;
		}
	}
	printf("%d\n",ans);
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/
