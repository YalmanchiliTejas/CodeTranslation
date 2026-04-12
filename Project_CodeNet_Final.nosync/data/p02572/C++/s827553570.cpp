#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fastin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod=1e9+7;
ll a[200010],ans,n,sum[200010];
int main(){
	cin>>n;
	rep(i,1,n)	scanf("%lld",&a[i]);
	rep(i,1,n)	sum[i]=sum[i-1]+a[i],sum[i]%=mod;
	rep(i,1,n){
		ll sumj=sum[n]-sum[i];
		sumj=(sumj%mod+mod)%mod;
		ans=(ans+sumj*a[i]%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
