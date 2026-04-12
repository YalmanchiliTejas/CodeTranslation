#include <bits/stdc++.h>
using namespace std;
#define data_type long long
#define endl "\n"
#define mod 1000000007
int main()
{
    data_type n,sum=0;
    cin>>n;
    vector<data_type>vc(n),prefix(n);
    for(auto &i:vc)
        cin>>i;
    prefix=vc;
    for(int i=n-2; i>=0; i--)
        prefix[i]+=prefix[i+1],prefix[i]%=mod;
    for(int i=0; i<n-1; i++)
        sum+=(vc[i]*prefix[i+1])%mod,sum%=mod;

    cout<<sum<<endl;

    return 0;

}

