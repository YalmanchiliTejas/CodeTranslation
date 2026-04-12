#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=10000005;
const int mod=998244353;
int n,ans;
int fac[maxn],ifac[maxn],pw2[maxn];
int C(int a,int b){
	if(a<b||a<0||b<0)return 0;
	return 1LL*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	scanf("%d",&n);
	fac[0]=ifac[0]=fac[1]=ifac[1]=1;
	for(int i=2;i<=n;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		ifac[i]=1LL*ifac[mod%i]*(mod-mod/i)%mod;
	}
	REP(i,n)ifac[i]=1LL*ifac[i-1]*ifac[i]%mod;
	pw2[0]=1;
	ans=1;
	REP(i,n){
		pw2[i]=2LL*pw2[i-1]%mod;
		ans=3LL*ans%mod;
	}
	for(int i=n/2+1;i<=n;i++){
		ans-=2LL*C(n,i)%mod*pw2[n-i]%mod;
		if(ans<0)ans+=mod;
	}
	printf("%d\n",ans);
	return 0;
}