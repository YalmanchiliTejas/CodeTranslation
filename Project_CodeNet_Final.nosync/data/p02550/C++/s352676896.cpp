#include<bits/stdc++.h>
using namespace std;
#define loop(i,x,z) for (int i=x;i<z;i++)
using ll = long long;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
const ll M = 998244353;
ll n,x,m;
//string s;
int main()
{
    cin>>n>>x>>m;
    x%=m;
    vector<bool>vis(m,0);
    ll ans=0;
    ll cnt=0;
    while(1)
    {
        //cout<<x<<" ";
        if(vis[x] || cnt>=n)break;
        vis[x]=1;
        ans+=x;
        x=x*x%m;
        cnt++;
    }
    //cout<<n<<" "<<cnt<<" ";
    n-=cnt;
    ll tem=0;
    cnt=0;
    loop(i,0,m)vis[i]=0;
    //cout<<n<<" "<<ans;
    while(1)
    {
        if(vis[x] || cnt>=n)break;
        //cout<<"yup";
        vis[x]=1;
        tem+=x;
        x=x*x%m;
        cnt++;
    }
    //cout<<cnt<<" "<<tem<<" ";
    if(cnt<n)
    {
        ll k=n/cnt;
        ans+=tem*k;
        n%=cnt;
        while(n-->0)
        {
            ans+=x;
            x=x*x%m;
        }
    }
    else ans+=tem;
    cout<<ans;
}