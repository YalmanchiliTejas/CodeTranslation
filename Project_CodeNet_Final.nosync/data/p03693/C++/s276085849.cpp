#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <bitset>
#include <cmath>
#include <utility>
#define Maxn 100005
#define Maxm 1000005
#define lowbit(x) x&(-x)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define PI acos(-1.0)
#define LL long long 
#define Inf (1LL<<62)
#define inf 0x3f3f3f3f
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
using namespace std;
int main()
{
	int r,g,b;
	while(cin>>r>>g>>b)
	{
		printf("%s\n",(r*100+g*10+b)%4?"NO":"YES");
	}
	return 0;
}