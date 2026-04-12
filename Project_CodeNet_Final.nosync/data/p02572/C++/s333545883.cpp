
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int val;
    vector<long long> v;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    int long long ans=0;
    int j;
    long long sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+v[i];
    }

    for(i=0;i<n;i++)
    {
        sum=sum-v[i];
        ans=(ans+((sum)%1000000007*(v[i]%1000000007))%1000000007)%1000000007;
    }
    cout<<ans;
    
  return 0;
}