#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int mod=1e9+7;
int main()
{
    fast
    int n;  cin>>n;
    ll z;
   ll sum=0;
    cin>>sum;
    ll res=0;
    for(int i=1;i<n;i++)
    {
        cin>>z;
        res+=((sum%mod)*(z%mod));
        res%=mod;
        sum+=z;
        sum%=mod;
      //  cout<<res<<endl;
    }
    cout<<res;



    return 0;
}
