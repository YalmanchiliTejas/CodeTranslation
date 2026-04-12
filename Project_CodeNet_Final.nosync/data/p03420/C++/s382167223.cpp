/********************************************
 *Author*        :ZZZZone
 *Created Time*  : 日  3/11 20:18:45 2018
 * Ended  Time*  : 日  3/11 20:43:42 2018
*********************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

inline void OPEN(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	if( k == 0) printf("%lld\n", 1LL * n * n);
	else{
		LL ans = 0;
		for(int i = k+1; i <= n; i++){
			int r = i-1, l = k;
			ans = ans + (r-l+1LL);
			while(r +k+1 <= n){
				l += i;
				r += i;
				ans = ans + (LL)(min(n, r)- min(n, l)+1LL);
			}
		}
		printf("%lld\n", ans);
	}
    return 0;
}
