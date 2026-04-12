#include<bits/stdc++.h>
using namespace std;
int ara[50];

int main()
{
    int n,cnt,i,a;
    scanf("%d",&n);
    cnt=1;
    scanf("%d",&ara[0]);
    a=ara[0];
    for(i=1; i<n; i++)
    {
        scanf("%d",&ara[i]);
        if(ara[i]>=a && ara[i]>=ara[0] && ara[i]>=ara[1])
        {
            cnt++;
            a=ara[i];
        }
    }
    printf("%d",cnt);
    
    return 0;
}
