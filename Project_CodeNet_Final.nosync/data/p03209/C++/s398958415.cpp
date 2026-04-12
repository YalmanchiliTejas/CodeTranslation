/*
wxy.

*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
namespace wxy{
	int n;const int maxn=50+9;
	ll len[maxn],pp[maxn];
}
using namespace wxy;
ll rs(ll x,int lv){
	if(x==len[lv]) return pp[lv];
	if(x<=1)
		return 0;
	if(x<=len[lv-1]+1)
		return rs(x-1,lv-1);
	if(x==len[lv-1]+2)
		return pp[lv-1]+1;
	if(x<=len[lv]-1)
		return pp[lv-1]+1+rs(x-len[lv-1]-2,lv-1);
}
int main(){
	cin>>n;
	len[0]=1;pp[0]=1;
	for(int i=1;i<=n;++i){
		len[i]=len[i-1]*2+3;
		pp[i]=pp[i-1]*2+1;
		//printf("i=%d len=%lld pp=%lld\n",i,len[i],pp[i]);
	}
	ll x;cin>>x;
	printf("%lld\n",rs(x,n));
	return 0;
}