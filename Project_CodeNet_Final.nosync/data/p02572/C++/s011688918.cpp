#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define N 0
#define INF 0x3f3f3f3f
#define LL long long
#define mz(x) ms(x,0)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcopy(x,y,sizeof(y))
#define MOD 1000000007

using namespace std ;

LL sum[200010] ;
LL a[200010] ;

int main()
{
	int n ;
	scanf ("%d", &n) ;
	
	for (int i=0; i<n; i++)
		scanf ("%lld", a + i) ;
	
	sum[0] = a[0] ;
	for (int i=1; i<n; i++)
		sum[i] = (sum[i-1] + a[i]) % MOD ;
	
	LL ans = 0 ;
	for (int i=n-1; i>0; i--)
		ans = (a[i] * sum[i-1] % MOD + ans) % MOD ;
		
	cout << ans << endl ;

	return 0 ;
}