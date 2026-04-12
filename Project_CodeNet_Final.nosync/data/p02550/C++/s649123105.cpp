#include <bits/stdc++.h>
#define ll long long
#define int long long
#define MOD 1000000007
#define mod 998244353
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define si set<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vvi vector<vi>
#define vvii vector<vii>
#define vsi vector<si>
#define endl "\n"
#define rep(i, n) for(i = 0; i < (n); i++)
#define rrep(i, n) for(i = (n - 1); i >= 0; i--)
#define MAXN 200001
#define read(arr,n) for(int i=0;i<n;i++)cin>>arr[i]
using namespace std;
void solve1();

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
bool comp(pii a,pii b)
{
    return a.ss<b.ss;
}
void solve()
{
    int t;cin>>t;
    while(t--)
    {
        solve1();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve1();
    return 0;
}
void solve1()
{
    int n,x,m;int ans=0;
    cin>>n>>x>>m;
    vi vec,vec2;vec.pb(x);
    map<int,int>me;
    me[x]=1;
    int a=1;
    int c=x;
    while(c!=0)
    {
        c=(c*c)%m;
        if(me[c]==1)break;
        if(c==0)break;
        me[c]=1;
        vec.pb(c);a++;
    }
    if(c==0)
    {
        for(int i=0;i<min((int)vec.size(),n);i++)
        {
            ans+=vec[i];
        }
        cout<<ans<<endl;return;
    }
    else
    {
        int sum=0,p=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==c)
            {
                p=i;
                for(int j=i;j<vec.size();j++)
                {
                    vec2.pb(vec[j]);
                }
                break;
            }
            sum+=vec[i];
        }
        if(n<p)
        {
            for(int i=0;i<p;i++)
            {
                ans+=vec[i];
            }
        }
        else
        {
            ans+=sum;n-=p;
            sum=0;
            for(int i=0;i<vec2.size();i++)
            {
                sum+=vec2[i];
            }
            int z=vec2.size();
            ans+=sum*(n/z);
            n%=z;
            for(int i=0;i<n;i++)
            {
                ans+=vec2[i];
            }
        }
    }
    cout<<ans<<endl;
}


