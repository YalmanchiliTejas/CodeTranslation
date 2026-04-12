/************************************************
 *Author*        :skyNebula
 *Created Time*  : 一  4/23 22:44:15 2018

*********************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
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
typedef pair<int, int> pii;
typedef long long LL;
const int mod = 1e9 + 7;
const int MaxN = 1e6;

int a,b,c,x,y,s,minn,maxn,z,ans;

int main()
{
	cin >> a >> b >> c >> x >> y;
	s = a + b;
	minn = min(x,y);
	maxn = max(x,y);
	z = maxn - minn;

	if(s >= 2 * c)
	    ans += minn * 2 * c;
	else 
	    ans += minn * s;
	if(a <= 2 * c && x == maxn)
	{
		ans += z * a;
	}
	else if(a > 2 * c && x == maxn)
	{
		ans += z * 2 * c;
	}
	else if(b > 2 * c && y == maxn)
	{
		ans += z * 2 * c;
	}
	else if(a <= 2 * c && y == maxn)
	{
		ans += z * b;
	}	
	cout << ans << endl;;
	return 0;
	
} 
