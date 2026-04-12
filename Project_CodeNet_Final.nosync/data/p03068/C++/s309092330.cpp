#include <bits/stdc++.h>
/// TONI BO$$ was here
/// #MLC

using namespace std;

char s[105];

int main()
{
    int i,n,k;
    ///freopen(".in","r",stdin);
    ///freopen(".out","w",stdout);
    scanf("%d\n%s\n%d",&n,s+1,&k);
    for(i=1; i<=n; i++)
        if(s[i]!=s[k])
            printf("*");
        else
            putchar(s[k]);

    return 0;
}
