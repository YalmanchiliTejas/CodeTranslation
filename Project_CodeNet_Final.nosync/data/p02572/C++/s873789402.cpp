#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast","no-stack-protector","unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define int long long
#define F(i,L,R) for(int i=L;i<R;++i)
#define FE(i,L,R) for(int i=L;i<=R;++i)
#define getI(a) scanf("%lld",&a)
#define getII(a,b) scanf("%lld%lld",&a,&b)
#define getIII(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define VgetI(n) int (n); scanf("%lld",&(n))
#define VgetII(n,m) int (n),(m); scanf("%lld%lld",&(n),&(m))
#define VgetIII(n,m,k) int (n),(m),(k); scanf("%lld%lld%lld",&(n),&(m),&(k))
#define debug(x) cout<<(#x)<<"="<<x<<"\n";
#define qq cout<<"QQ\n";
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define INF 2000000000
int a[200005],MOD=1000000007;
main(){
	int n;
	while(~getI(n)){
		F(i,0,n) getI(a[i]);
		int sum=0,ans=0,sumNow=0;
		F(i,0,n) sum+=a[i];
		F(i,0,n){
			sumNow+=a[i];
			ans+=a[i]*((sum-sumNow)%MOD);
			assert((sum-sumNow)>=0);
			ans%=MOD;
		}
		printf("%lld\n",ans);
	}
}
