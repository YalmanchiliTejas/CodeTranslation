#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<int,int> Pair;
const int INF = 1e9+7;

LL ans;
int n, k;

int main(){
	scanf("%d%d", &n, &k);
	if (k==0){
		for (int b=1; b<=n; ++b)
			ans+=n/b*b+n%b;
		printf("%lld\n", ans);
		return 0;
	}
	for (int b=k+1; b<=n; ++b){
		ans+=b-k;
		for (int i=1; (i+1)*b<=n; ++i)
			ans+=b-k;
		if (n%b!=0 && n>b) ans+=max(0, n%b-k+1);
	}
	printf("%lld\n", ans);
	
	return 0;
}
