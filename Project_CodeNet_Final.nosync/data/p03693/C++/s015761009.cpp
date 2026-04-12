#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,ans=0;
    for(int i=1;i<=3;i++)
    {
        scanf("%d",&a);
        ans=ans*10+a;
    }
    ans%4==0?printf("YES\n"):printf("NO\n");
    return 0;
}