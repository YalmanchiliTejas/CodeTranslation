#include<bits/stdc++.h>
#define ll long long int
#define fin for(i=0;i<n;i++)
#define vec vector<ll>
#define pb push_back
#define vecit vector<ll>::iterator
#define vecp vector<pair<ll,ll> >
#define vecpit vector<pair<ll,ll> >::iterator
#define mapp map<ll,ll>
#define mapr map<ll,pair<ll,ll> >
#define maprit map<ll,pair<ll,ll> >::iterator
#define mapit map<ll,ll>::iterator
#define mod1 1000000007
#define INF 10000000000
using namespace std;
/*ll od(ll i,ll j, vec v)
{
    if(i>j)
        return 0;
     if(i==j)
        return v[i];
    ll p=v[i];
    ll q=v[j];
    ll r=od(i+1,j-1,v);
    return (max(p,q)+min(min(p,q),r)-max(min(p,q),r));
}
ll ev(ll i,ll j,vec v)
{
    ll p,q;
    p=v[i]-od(i+1,j,v);
    q=v[j]-od(i,j-1,v);
    cout<<p<<q<<"\n";
    return max(p,q);
}*/
vector<vec >dp(3005,vec (3005,0));
ll od( vec v)
{
    ll i,j,k,l,n;
    n=v.size();
    for(i=n-1;i>=0;i--)
    {
        for(j=i;j<n;j++)
        {
            if(i==j)
                dp[i][j]=v[i];
            else
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
int main()
{
    ll n;
    cin>>n;
    ll i,j,k,l;
    vec v;
    fin
     {
         cin>>j;
         v.pb(j);
     }

        k=od(v);
     cout<<k;
}
