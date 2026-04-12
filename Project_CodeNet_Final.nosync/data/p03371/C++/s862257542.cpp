#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <assert.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int main() {
	int a,b,c,x,y;
	lli ans=1e18;

	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	for(int i=0;i<=max(x,y);i++) {
		ans = min(ans,2ll*i*c+1ll*max(0,(x-i))*a+1ll*max(0,(y-i))*b);
	}
	printf("%lld\n",ans);
	
}
