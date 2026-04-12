#include<bits/stdc++.h>
#define ll long long
#define mo 1000000007
using namespace std;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	ll ans=0;
	for (int i=1;i<=n;i++){
		int times=n/i;
		ans+=n;
		ans-=times*min(i,k);
		ans-=min(k,n%i+1);
		ans+=(k!=0);
	}
	printf("%lld\n",ans);
}