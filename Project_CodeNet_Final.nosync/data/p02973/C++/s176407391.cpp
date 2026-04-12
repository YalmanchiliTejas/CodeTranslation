#include<bits/stdc++.h>

using namespace std;

using ll=int64_t;

ll lis(vector<ll>a)
{
    int n=a.size();
    const ll INF=1e10;
    vector<ll>d((n+1),INF);
    d[0]=-1*INF;

    for(int i=0;i<n;i++)
    {
        ll j=upper_bound(d.begin(),d.end(),a[i])-d.begin();
        if(d[j-1]<=a[i]&&a[i]<=d[j])
            d[j]=a[i];
    }
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        if(d[i]<INF)
            ans=i;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<ll>v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i]*=-1;
    }

    cout<<lis(v)<<endl;
}
