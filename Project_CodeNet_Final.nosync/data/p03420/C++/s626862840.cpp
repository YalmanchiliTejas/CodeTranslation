#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int b=m+1;b<=n;++b){
		int lim=n/b;
		for(int t=0;t<=lim;++t) {
			if(t*b+b-1<=n) ans+=b-m;
			else if(t*b+m<=n) ans+=n-t*b-m+1;
		}
//		cerr<<b<<' '<<ans<<endl;
	}
	if(m==0) ans-=n;
	printf("%lld",ans);
}