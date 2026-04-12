#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define mod 1000000007

const int sz=1e5+5;
ll inf=1e15;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll sum=0;
        ll ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
            sum+=ar[i];
            sum%=mod;
        }
        ll res=0;
        for(int i=0;i<n;i++){
            sum=(sum%mod-(ar[i]%mod)+mod)%mod;
            res=(res%mod+(sum*ar[i])%mod)%mod;
        }
        cout<<res;
    }

    return 0;
}