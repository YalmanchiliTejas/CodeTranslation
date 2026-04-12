#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 998244353
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
ll n,k[10000005],kinv[10000005],inv[10000005],ans,sum;
ll cm(ll x,ll y){
	if(y<0||x<y)return 0;
	return k[x]*kinv[y]%M*kinv[x-y]%M;
}
int main(void){
	cin>>n;
    k[0]=1LL,inv[0]=1LL,inv[1]=1LL,kinv[0]=1LL;
    for(ll i=2;i<=n;i++)inv[i]=M-(M/i)*inv[M%i]%M;
    for(ll i=1;i<=n;i++)k[i]=k[i-1]*i%M,kinv[i]=kinv[i-1]*inv[i]%M;
    ans=1LL,sum=1LL;
    for(ll i=1;i<=n;i++){
		sum=sum*2LL%M;
		sum=(M+sum-cm(i-1LL,n/2LL)*2LL%M)%M;
		ans=(ans+sum*cm(n,i)%M)%M;
	}
	cout<<ans<<endl;
}
