#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<ctime>
#include<algorithm>
#include<sstream>
#include<bitset>
#define scand(a) scanf("%d",&a)
#define scandd(a,b) scanf("%d%d",&a,&b)
#define scanddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) (x&-x)
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
const int maxn=1e4+5;
const ll mod=1e9+7;

int main()
{
	#ifdef local
	freopen("1.txt","r",stdin);
	#endif
	int x;
	scand(x);
	if(x>=30)printf("Yes\n");
	else printf("No\n");
}