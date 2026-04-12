#include <bits/stdc++.h>
using namespace std;
signed a,b,c;
signed main()
{
    scanf("%d%d%d",&a,&b,&c),a-=c,printf("%d\n",a/(b+c));
    return 0;
}