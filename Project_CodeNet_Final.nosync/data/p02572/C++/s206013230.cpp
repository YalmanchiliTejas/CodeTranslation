#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
int n;
int a[200005];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll sum=a[1],ans=0;
	for(int i=2;i<=n;i++){
		ans=(ans+sum*(ll)a[i]%mod)%mod;
		sum=(sum+(ll)a[i])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
