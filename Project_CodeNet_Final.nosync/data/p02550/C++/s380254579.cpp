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

LL idx[100010] ;
vector<LL> cycle ;

LL mod_mul (LL x, LL y, LL p) {
		LL s = 0 ;
		while (y > 0) {
				if (y & 1) {
						s += x ;
						s %= p ;
				}
				x <<= 1 ;
				x %= p ;
				y >>= 1 ;
		} return s ;
}

int main()
{
	LL n, x, m ;
	scanf ("%lld%lld%lld", &n, &x, &m) ;
	
	LL s = x ;
	idx[x] = 1 ;
	cycle.push_back(0) ;
	cycle.push_back(x) ;
	LL i, j = -1 ;
	for (i=2; i<=n; i++)
	{
		x = mod_mul (x, x, m) ;
		if (idx[x] > 0)
		{
			j = idx[x] ;
			break ;
		}
		idx[x] = i ;
		cycle.push_back(x) ;
		s += x ;
	}
	
	if (j == -1)
		cout << s << endl ;
	else
	{
		LL cn = i - j ;
		LL res = n - i + 1 ;
		LL cs = 0 ;
		for (LL k=j; k<i; k++)
			cs += cycle[k] ;
			
		s += res / cn * cs ;
		if (res % cn)
			for (LL k=j; k<j+(res%cn); k++)
				s += cycle[k] ;
		
		cout << s << endl ;
	}

	return 0 ;
}