#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define db cout<<"db: "
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define all(v) v.B,v.E
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clk1 clock_t start_time=clock()
#define clk2 cout<<(clock()-start_time)/(double)CLOCKS_PER_SEC
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int main()
{
    int i,j,t;
    boost;

    ll n,x,m;
    cin>>n>>x>>m;
    map<ll,pair<ll,ll>> mp;
    mp[x]={0,0};

    ll sum=x;
    ll ans=0;
    ll len=1;
    ll clen=-1;
    ll cycle=-1;

    rep(i,2,n+1)
    {
        x= (x*x)%m;
        if(mp.count(x))
        {
            clen = len-mp[x].S;
            cycle=sum-mp[x].F;
            break;
        }

        mp[x]={sum,len};
        len++;
        sum+=x;
    }

    if(cycle==-1)
    {
        cout<<sum;return 0;
    }

    ans = sum-cycle;
    ll rem = n-(len-clen);
    ll cnt = rem/clen;
    ans+= cnt*cycle;
    rem-= cnt*clen;
    while(rem--)
    {
        ans+=x;
        x=(x*x)%m;
    }

    cout<<ans;

    return 0;
}