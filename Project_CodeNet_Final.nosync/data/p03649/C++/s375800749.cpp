#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
ll a[55],ans;
int n;
int main() {    
	scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i) 
    	scanf("%lld",&a[i]); 
    while(1) {
    	int t = 1;
    	for(int i=2;i<=n;++i)
        	if(a[i]>a[t]) t=i;
    	if(a[t]<n) break;
    	ll k = (a[t]-(n -1)-1)/n + 1;
    	a[t]-= k*n;
    	ans += k;
    	for(int i = 1 ; i <= n ; ++i)
        	if(i != t) a[i] += k;
    }
    printf("%lld\n",ans);
    return 0;
}