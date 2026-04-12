//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
const int N=500023;
bool vis[N];
vector <int> adj[N];
void solve()
{
    ll n;
    cin>>n;
    vl v;
    v.pb(0);
    rep(i,n)
    {
        ll c;
        cin>>c;
        v.pb(c);
    }
    ll dp[n+1];
    dp[1]=1;
    multiset <ll> s;
    s.insert(v[1]);
    for(int i=2;i<=n;i++)
    {
        auto it=s.lower_bound(v[i]);
        if(it==s.begin())
        {
            dp[i]=dp[i-1]+1;
            s.insert(v[i]);
        }
        else
        {
            it--;
            s.erase(it);
            dp[i]=dp[i-1];
            s.insert(v[i]);
        }
    }
    cout<<dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
}