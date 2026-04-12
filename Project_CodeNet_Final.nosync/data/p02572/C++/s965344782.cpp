#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t=1,i,j,k,a,b,n,x,y,m;
    cin>>n;
    ll cnt,f=0;
    vector<ll>v,u;
    ll sum=0;
    m=1000000007;
    for(i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    for(i=n-1;i>=0;i--)
    {
        sum=(sum+v[i]);
       // cout<<sum<<endl;
        u.push_back(sum);
    }
    reverse(u.begin(),u.end());
//    cout<<u[0]<<endl;
//    cout<<u[1]<<endl;
    ll ans=0,p=0;
    for(i=0;i<n;i++)
    {
        p=u[i]-v[i];
        ans=((ans%m)+(((p%m)*(v[i]%m)))%m)%m;
    }
    cout<<ans%m<<endl;
    return 0;
}
