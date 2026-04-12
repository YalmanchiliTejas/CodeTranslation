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
int N,M,K;
int f(){
	int res=0;
	REP(i,M){
		res+=nCk(N*M-2,K-2)*N%mod*N%mod*(M-i)%mod*i%mod;
		res%=mod;
	}
	return res;
}
signed main(){
	init_perm();
	cin>>N>>M>>K;
	int ans=0;
	ans+=f();
	swap(N,M);
	ans+=f();
	cout<<ans%mod<<endl;
}
