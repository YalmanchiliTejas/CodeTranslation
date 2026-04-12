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
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double pi = acos(-1.0);
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
inline void write(ll a){
    if (a<0) putchar('-'),a=-a;
    if (a>=10) write(a/10); putchar(a%10+'0');
}
const int MAX_N=2e5+10;
int a[MAX_N],b[MAX_N],n; 
int main()
{
 	#ifdef TEST
	 	freopen("input.txt","r",stdin);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		b[i]=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(b[i]<a[n>>1])
		{
			printf("%d\n",a[n>>1]);
		}
		else
		{
			printf("%d\n",a[(n-1)>>1]);
		}
	}
	return 0;
}

