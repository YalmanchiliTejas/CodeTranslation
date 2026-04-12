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
const int mod=1e9+7;
int main()
{
	//input;output;
	int arr[Maxn<<1],ans[Maxn<<1],n,front,rear;
	while(~scanf("%d",&n))
	{
		front=0;rear=n-1;
		for(int i=0;i<n;i++)
			scanf("%d",arr+i);
		for(int i=n-1;i>=0;i--)
		{
			if((i-(n-1))&1)
				ans[rear--]=arr[i];
			else
				ans[front++]=arr[i];
		}
		for(int i=0;i<n;i++)
			printf("%d%c",ans[i],i==n-1?'\n':' ');
	}
	return 0;
}