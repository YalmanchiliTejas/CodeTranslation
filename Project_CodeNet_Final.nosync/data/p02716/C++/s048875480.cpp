#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[200010], n;
map<int, ll> mem[200010];
ll dp(int x, int nm){
	if(nm==1){
		if(x>=n)
			return -1e17;
		return a[x];
	}
	if(n-x<(nm-1)*2+1){
		return -1e17;
	}
	if(mem[x].count(nm)){
		return mem[x][nm];
	}
	ll res=a[x];
	res=a[x]+dp(x+2, nm-1);
	// if((n-x-2)>2*(nm-1)){
		res=max(res, a[x]+dp(x+3, nm-1));
	// }
	mem[x][nm]=res;
	return res;
}
int main(){
    while(cin>>n){
        ll ans=0;
        for(int i=0; i<n; ++i){
        	mem[i].clear();
            scanf("%d",a+i);
        }
        ans=max(dp(0, n/2), dp(1, n/2));
        ans=max(ans, dp(2, n/2));
        printf("%lld\n",ans);
    }
  return 0;
}


