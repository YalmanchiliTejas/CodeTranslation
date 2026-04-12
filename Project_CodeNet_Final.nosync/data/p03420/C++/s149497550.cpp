#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
#define dpb push_back
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
const int inf = 1e9;

#define int long long
signed main(){
	int n, k;
	scanf("%lld%lld", &n, &k);
	int ans = 0;
	for(int b = 1;b <= n;b++){
		if(k >= b)continue;
		int a = n;
		int x = (b-k)*(a/b);
		//int y = 0;
		int y = max((int)0, (a%b-k+1));
		if(k == 0)y = max((int)0, (a%b-k));
		ans += x+y;
		//printf("%lld %lld %lld\n", b, x, y);
	}
	printf("%lld\n", ans);
	return 0;
}