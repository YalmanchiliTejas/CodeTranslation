#include<bits/stdc++.h>
using namespace std;

long long a[200005],b[200005];

int main()
{
    int n,i;
    long long ans=0,m=1000000007;

    cin>>n;

    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    for(i=1;i<=n;i++){
        ans=(ans+((b[i-1]%m)*(a[i]%m))%m)%m;
    }
    cout<<ans<<"\n";

    return 0;
}



