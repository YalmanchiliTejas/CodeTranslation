#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    ll arr[n+2];
    ll sum=0;
    ll mod=1e9+7LL;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum +=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        sum -= arr[i];
        ll tmp=((sum%mod)*(arr[i]%mod))%mod;
        res += tmp;
        res=res%mod;
    }
    cout<<res<<endl;
    return 0;
}
