#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 55
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll x,b[maxn],p[maxn];
ll calc(int n,ll x){
	if(n == 0) return x ? 1 : 0;
	ll nump = 0;
	if(x <= 1) return nump;
	--x;
	if(x < b[n - 1] + p[n - 1]) return nump + calc(n - 1,x);
	nump += p[n - 1], x -= b[n - 1] + p[n - 1];
	if(x <= 1) return nump + x;
	--x, ++nump;
	if(x < b[n - 1] + p[n - 1]) return nump + calc(n - 1,x);
	nump += p[n - 1], x -= b[n - 1] + p[n - 1];
	return nump;
}
int main(){
	scanf("%d%lld",&n,&x);
	b[0] = 0, p[0] = 1;
	for(int i=1;i<=n;i++){
		b[i] = 2 * b[i - 1] + 2, p[i] = 2 * p[i - 1] + 1;
	}
	printf("%lld\n",calc(n,x));
	return 0;
}
