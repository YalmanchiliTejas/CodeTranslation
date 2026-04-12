#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int modn=1e9+7;
ll mulit(ll a,ll b,ll m){
    ll ans=0;
    while(b){
        if(b&1) ans=(ans+a)%m;
        a=(a<<1)%m;
        b>>=1;
    }
    return ans;
}

ll quick_mod(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans=mulit(ans,a,m);
        }
        a=mulit(a,a,m);
        b>>=1;
    }
    return ans;
}

ll comp(ll a,ll b,ll m){
    if(a<b) return 0;
    if(a==b) return 1;
    if(b>a-b) b=a-b;
    ll ans=1,ca=1,cb=1;
    for(int i=0;i<b;i++){
        ca=ca*(a-i)%m;
        cb=cb*(b-i)%m;
    }
    ans=ca*quick_mod(cb,m-2,m)%m;
    return ans;
}

ll lucas(ll a,ll b,ll m){
    ll ans=1;
    while(a&&b){
        ans=(ans*comp(a%m,b%m,m))%m;
        a/=m;
        b/=m;
    }
    return ans;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	ll r=n*1ll*m;
	ll q=lucas(r-2,k-2,modn);
	ll sum=0;
	for(int i=1;i<n;i++){
		sum=(sum+q*i%modn*m%modn*m%modn*(n-i)%modn)%modn;
	}
	for(int i=1;i<m;i++){
		sum=(sum+q*i%modn*n%modn*n%modn*(m-i)%modn)%modn;
	}
	printf("%lld\n",sum);
}
