#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

ll a[200010];
const ll mod=1e9+7;
int main(){
	int n;
	ll sum=0;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	
	ll ans=0,tmp=0;
	for(int i=0;i<n;i++){
		tmp+=a[i];
		ans=(ans+a[i]*((sum-tmp)%mod)%mod)%mod;
	}
	
	printf("%lld",ans);
}