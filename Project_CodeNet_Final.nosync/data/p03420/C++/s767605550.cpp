#include<bits/stdc++.h>
using namespace std;
long long cal;
main()
{
	int t,p;
    scanf("%d%d",&t,&p);
    if(p==0)
    {
        cal=t;
        cal*=t;
        printf("%lld",cal);
        return 0;
    }
    for(int i = p+1;i <= t;i++)
    {
        for(int j = p,co=1;j <= t;j+=i,co++)
        {
            cal+=min(co*i,t+1)-j;
        }
    }
    printf("%lld",cal);
}
