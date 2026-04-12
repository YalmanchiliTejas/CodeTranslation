#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 5000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
int main()
{
    int a,b,ans=0,max1=0;
    scanf("%d",&a);
    for(int i=1;i<=a;i++)
    {
        scanf("%d",&b);
        if(b>=max1)
        max1=b,ans++;
    }
    printf("%d\n",ans);
}