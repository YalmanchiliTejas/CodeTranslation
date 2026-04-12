#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;ll ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int b=k+1;b<=n;++b){
		int t=(n+1)/b;
		ans+=ll(b-k)*t;
		t=t*b+k;
		ans+=max(0,n-t+1);
	}
	if(!k)ans-=n-(k+1)+1;
	printf("%lld\n",ans);
	return 0;
}