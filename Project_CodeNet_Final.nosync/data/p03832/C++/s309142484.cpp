#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define all(a)  a.begin(), a.end()
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const double eps = 1e-8;
#define EQ(a,b) (fabs((a)-(b))<eps)
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
const int mod = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;

ll power(ll a,ll n){
	if(n==0){
		return 1;
	}
	ll b = power(a,n/2);
	b = b*b%mod;
	if(n%2) b= b*a%mod;
	return b;
}

int add(int a,int b){ return (a+b)%mod;}
int mul(int a,int b){ return (ll)a*b%mod;}

int n,a,b,c,d;
ll dp[1010][1010],fac[1010],inv[1010][1010],nCk[1010][1010];

ll f(int i,int l){
	if(i==b+1){
		if(!l) return 1;
		return 0;
	}
	ll &ret = dp[i][l];
	if(ret!=-1) return ret;
	ret = f(i+1,l);
	int e = c;
	while(e<=d && e*i<=l){
		ret = (ret + f(i+1,l-e*i)*nCk[l][e*i]%mod*fac[e*i]%mod*inv[i][e]%mod*inv[e][1]%mod)%mod;
		e++;
	}
	return ret;
}

int main(){
 // 	freopen("nice.in","r",stdin);
 // freopen("nice.out","w",stdout);
	REP(i,1010){
		nCk[i][0]=1;
		REPP(j,1,i+1){
			nCk[i][j]=(nCk[i-1][j-1]+nCk[i-1][j])%mod;
		}
	}
	fac[0]=inv[0][0]=1;
	REP(i,1010) inv[0][i]=1;
	REPP(i,1,1010){
		fac[i]=fac[i-1]*i%mod;
		inv[i][0]=1;
		inv[i][1]=power(fac[i],mod-2);
		REPP(j,2,1010) inv[i][j]=inv[i][j-1]*inv[i][1]%mod;
	}
	scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
	FILL(dp,-1);
	printf("%lld\n",f(a,n));
	return 0;
}


