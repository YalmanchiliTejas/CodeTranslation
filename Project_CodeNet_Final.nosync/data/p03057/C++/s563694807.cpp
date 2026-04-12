#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=401000;
char s[N];
int n,m;

ll dp[N],sdp[N],ans;

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	bool mono=1;
	rep(i,0,m) mono&=s[i]==s[0];
	if (mono) {
		int a=2,b=1;
		rep(i,1,n) {
			a=(a+b)%mod;
			swap(a,b);
		}
		printf("%d\n",b);
		return 0;
	}
	int sR=2*n+1,sB=1;
	if (s[0]=='B') {
		rep(i,0,m) if (s[i]=='R') s[i]='B'; else s[i]='R';
	}
	rep(l,0,m) {
		int r=l;
		while (r<m&&s[r]==s[l]) r++;
		int len=r-l;
		if (len%2==0) {
			if (l==0) len=len+1;
			else len=2*n+1;
		}
		if (r==m) break;
		if (s[l]=='R') sR=min(sR,len);
		else sB=min(sB,len);
		l=r-1;
	}
	if (n%2==1) {
		puts("0");
		return 0;
	}
//	printf("%d %d\n",sR,sB);
	auto solve=[&](int sR,int sB) {
		memset(dp,0,sizeof(dp));
		memset(sdp,0,sizeof(sdp));
		dp[0]=1;
		sdp[2]=1;
		rep(i,1,n+1) {
			if (i%2==1) {
				dp[i]=(sdp[i+1]-sdp[max(0,i-sR)])%mod;
			} else {
				if (i!=n) {
					dp[i]=(sdp[i+1]-sdp[max(1,i-sB)])%mod;
				} else {
					for (int j=1;j<=sB&&j<=i;j+=2) {
						dp[i]=(dp[i]+dp[i-j]*j)%mod;
					}
					dp[i]%=mod;
				}
			}
			sdp[i+2]=(sdp[i]+dp[i])%mod;
		}
		ans+=dp[n];
	};
	solve(sR,sB);
	solve(sB,sR);
	ans%=mod;
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);
}