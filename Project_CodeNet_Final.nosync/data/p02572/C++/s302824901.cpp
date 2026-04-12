/*
 * Created By : pash123
 * 2020-08-29-17.21
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int M=1e9+7;
vector<ll> prefSum;

int main()
{
    int n;
    cin>>n;
    int a[n];
    ll sum=0;
    for(int i=0;i<n;++i)
        {
            cin>>a[i];
            sum+=a[i];
            prefSum.push_back(sum);
        }
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        ans= ((ans%M) + ((((a[i]%M) *((prefSum[n-1]-prefSum[i])%M))%M)%M))%M;
    }
    cout<<ans;
    return 0;
}
