#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
#define EPS 1e-8
using namespace std;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double pi = acos(-1.0);
int read()
{
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar()) ret=ret*10+ch-'0';
	return ret;
}
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if((x*100+y*10+z)%4)
	{
		puts("NO");
		return 0;
	}
	 puts("YES");
	return 0;
}

