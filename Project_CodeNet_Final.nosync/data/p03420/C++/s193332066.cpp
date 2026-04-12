#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;

int n,k;

int main() {
	scanf("%d %d",&n,&k);
	LL ans=0;
	for(int b=k+1;b<=n;b++) {
		for(int i=0;i*b<=n;i++) {
			int x_low=max(k,-i*b+1);
			int x_up=min(b-1,n-i*b);
			ans+=max(0,x_up-x_low+1);
		}
	}
	printf("%lld\n",ans);
}