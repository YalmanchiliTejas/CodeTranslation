//#pragma comment(linker, "/STACK:102400000,102400000") 手动扩栈
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#include <set> //插入时相同的不插，边插边排序，里面还有multiset可以重复
#include <algorithm>
inline int read(){int now=0;register char c=getchar();for(;!isdigit(c);c=getchar());
for(;isdigit(c);now=now*10+c-'0',c=getchar());return now;}
#define foc(i,x,y) for(int i = x ; i <= y ; i ++)
#define rea(i,x,y) for(int i = x ; i >= y ; i --)
#define scf(a) scanf("%d",&a)
#define sca(a,b) scanf("%d%d",&a,&b)
#define pri(a) printf("%d\n",a)
#define pri_(a) printf("%d ",a)
#define prn printf("\n")
#define mem(a) memset(a,0,sizeof(a))
#define LL unsigned long long
using namespace std;
const double eps = 1e-9;
const int maxn = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
LL num[100],sum[100];
LL dfs(LL n,LL m)
{
    if(n==0)
        return 1;
    if(m<=1)
    {
        return 0;
    }
    else if(m<=num[n-1]+1)
    {
        return dfs(n-1,m-1);
    }
    else if(m==num[n-1]+2)
    {
        return sum[n-1] + 1;
    }
    else if(m<num[n])
    {
        LL s = sum[n-1] + dfs(n-1,m-2-num[n-1]) + 1;
        return s;
    }
    else if(m==num[n])
    {
        return sum[n];
    }
}
int main()
{
    num[0] = 1;
    sum[0] = 1;
    foc(i,1,55)
    {
        num[i] = (num[i-1] * 2) + 3;
        sum[i] = (sum[i-1] * 2) + 1;
    }
    LL n,m;
    cin >> n >> m;
    cout << dfs(n,m) << endl;
    return 0;
}
