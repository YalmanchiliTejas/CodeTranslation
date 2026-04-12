#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int mod_pow(int x,int y,int m=mod){
	int res=1;
	while(y>0){
		if(y&1)(res*=x)%=m;
		(x*=x)%=m;
		y>>=1;
	}
	return res;
}
vector<int>perm,inv;
void init_perm(){
	int x=1e6+1;perm.resize(x);inv.resize(x);
	perm[0]=1;
	REP(i,x+1)perm[i]=perm[i-1]*i%mod;
	inv[x]=mod_pow(perm[x],mod-2);
	for(int i=x-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
int nCk(int x,int y){
	if(x<y)return 0;
	return perm[x]*inv[x-y]%mod*inv[y]%mod;
}
int N,A,B,C,D;
int dp[1005][1005];
signed main(){
	init_perm();
	cin>>N>>A>>B>>C>>D;
	dp[0][A]=1;
	rep(i,N){
		for(int j=A;j<=B;j++){
			(dp[i][j+1]+=dp[i][j])%=mod;
			int now=1,rem=N-i;
			for(int k=1;k<=D&&i+j*k<=N;k++){
				(now*=nCk(rem,j))%=mod;rem-=j;
				if(C<=k)(dp[i+k*j][j+1]+=dp[i][j]*now%mod*inv[k]%mod)%=mod;
			}
		}
	}
	int ans=0;
	rep(i,N+2)(ans+=dp[N][i])%=mod;
	cout<<ans<<endl;
}
