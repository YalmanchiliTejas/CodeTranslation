#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=1,t=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=t) ans++,t=a[i];
    }
    cout<<ans<<endl;
}
