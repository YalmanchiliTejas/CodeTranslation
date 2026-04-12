#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#define mem(a, b) memset(a, (b), sizeof(a))
 
using namespace std;
 
 
typedef long long ll;
const int Maxn = 1e9 + 10;
const int N = 1e6 + 10;
const int INF=(0x7fffffff)/2;
const int MOD = 1000000007;
const int MaxN = 1000;
 
int a[110];
int main(){
	int a, b, c, x, y;
	while(~scanf("%d %d %d %d %d", &a,&b, &c, &x, &y)){
		int k = min(x, y), h = max(x , y);
		ll sum = 0;
		sum = a *x + b * y;
		ll s= k * 2 * c;
		if(x >= y) s += (x - y) * a;
		else s += (y - x) * b;
		ll ss= h  * 2 *c;
		s= min(s, ss);
		ll ans = min(sum, s);
		printf("%lld\n", ans);
	}
}
