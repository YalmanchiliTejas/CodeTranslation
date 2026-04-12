#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1005000;
#define ll long long
ll a[100];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll i,j,k,m,n;
    ll cnt=0,ans,flag=1;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    while(flag)
    {
        k=1;
        if(a[k]<n)
            flag=0;
        for(i=2; i<=n; i++)
            if(a[i]>a[k]&&a[i]>=n)
            {
                flag=1;
                k=i;
            }
        if(flag)
        {
            ans=a[k]/n;
            cnt+=ans;
            a[k]%=n;
            for(i=1; i<=n; i++)
                if(i!=k)
                    a[i]+=ans;
        }

    }
    cout<<cnt<<endl;
    return 0;
}
