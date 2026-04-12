#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int>v;
const int N=2e5+9;
/*ll mod=998244353;
ll dp[N];
int x,k;
ll f (int i)
{
    if (i==x)
        return 1;
    if (dp[i]!=-1)
        return dp[i];
    ll ans=0;
    for (int j=0; j<v.size(); j++)
    {
        if (i+v[j]<=x)
        {
            ans+=f(i+v[j]);
            ans%=mod;
        }
        else
            break;
    }
    return dp[i]=ans;
}*/
int main()
{
    FASTINOUT;
    ll n,x,m;
    cin>>n>>x>>m;
    ll ans=0,i;
    bool zero=0;
    vector<ll>v;
    map<ll,bool>visited;
    for (i=1; i<=n; i++)
    {
        v.push_back(x);
        ans+=x;
        x*=x;
        x%=m;
        if (visited[x])
            break;
        visited[x]=1;
        if (!x)
        {
            zero=1;
            break;
        }
    }
    if (zero)
    {
        cout<<ans<<endl;
        return 0;
    }
    if (i==n+1)
        i--;
    n-=i;
    if (!n)
    {
        cout<<ans;
        return 0;
    }
    ll pos=0;
    for (int j=0; j<v.size(); j++)
    {
        if (v[j]==x)
        {
            pos=j;
        }
    }
    ll k=0;
    for (int j=pos; j<v.size(); j++)
    {
        k+=(v[j]);
    }
    ll num=v.size()-pos;
    ll o=n/num;
    ans+=(o*k);
    n%=num;
    for (int j=pos; j<pos+n; j++)
    {
        if (j==v.size())
            break;
        ans+=v[j];
    }
    cout<<ans;
    /* cin>>x>>k;
     int l,r;
     for (int i=0; i<k; i++)
     {
         cin>>l>>r;
         for (int j=l; j<=r; j++)
         {
             v.push_back(j);
         }
     }
     sort(v.begin(),v.end());
     memset(dp,-1,sizeof dp);*/

    return 0;
}
