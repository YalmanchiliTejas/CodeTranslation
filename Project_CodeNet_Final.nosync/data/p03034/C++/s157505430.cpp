#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i,l,r) for (ll i=l;i<=r;i++)
ll N,M,a,b,c,t,ans,q[100007],qw[100007];
int main (){
	scanf("%lld",&N);
	rep(i,1,N) scanf("%lld",&q[i]);
	rep(i,1,N){
		ll p1=1,p2=N,s=0;
		while (p1+i<N){
			p1+=i;if (qw[p1]==i) break;s+=q[p1];qw[p1]=i;
			p2-=i;if (qw[p2]==i) break;s+=q[p2];qw[p2]=i;
			if (p2>i+1) ans=max(ans,s);
		}
	}
	printf("%lld\n",ans);
    return 0;
}
