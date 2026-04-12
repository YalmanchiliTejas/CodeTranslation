#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],dp[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        if(dp[len]>=a[i])
            dp[++len]=a[i];
        else
        {
            int p,l=1,r=len;
            while(l<r)
            {
                int m=l+r>>1;
                if(dp[m]>=a[i])
                    l=m+1;
                else
                    r=m;
            }
            dp[l]=a[i];
        }
    }
    cout<<len<<endl;
    return 0;
}
