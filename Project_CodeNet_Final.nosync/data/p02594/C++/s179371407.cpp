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

int main()
{
	int x ;
	scanf ("%d", &x) ;
	
	if (x >= 30)
		cout << "Yes" << endl ;
	else
		cout << "No" << endl ;

	return 0 ;
}