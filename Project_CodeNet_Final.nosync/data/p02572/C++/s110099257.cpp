#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define db double
#define pll pair<ll,ll>
#define pdb pair<db,db>
#define ldb long double
#define clr(x) memset(x,0,sizeof(x))
#define count_bit(x) __builtin_popcount(x)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
const int size1 = 1e5+7;
const int size2 = 1e4;

//ll fact[size1];
 
ll pw(ll x,ll y,ll mod)
{
    if(y==0)return 1;
    ll p =pw(x,y/2,mod);
    p = (p*p)%mod;
    if(y%2==1)p = (p*x)%mod;
    return p;
}
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	a = a%b;
	return gcd(b,a);
}
// ll inverse(ll x,ll mod)
// {
//     return pw(x,mod-2,mod);
// }
// ll ncr(ll n,ll r,ll mod)
// {
//     ll num = fact[n];
//     ll den = (fact[r] * fact[n-r])%mod;
//     den = inverse(den,mod);
 
//     ll ans = (num*den)%mod;
//     return ans;
// }
// vector<ll> adj1[size1];
// vector<ll> adj[size1];
// ll d[size1];
// ll n,m;
// void dikstra(ll s)
// {
//     for(ll i=1;i<=n;i++)d[i]=1e9;
//     d[s] = 0;
//     priority_queue<pll, vector<pll>, greater<pll>> q;
//     q.push({0, s});
//     while(!q.empty())
//     {
//         ll v = q.top().ss;
//         ll d_v = q.top().ff;
//         q.pop();
//         if(d_v!=d[v])continue;
//         for(auto to:adj1[v])
//         {
//             ll len = 1;
//             if(d[v] + len < d[to])
//             {
//                 d[to] = d[v]+len;
//                 q.push({d[to],to});
//             }
//         }
//     }
// }
// vector<ll> adj[size1];
// void dfs(ll v,ll p)
// {
// 	for(auto u:adj[v])
// 	{
// 		if(u!=p)
// 		{
// 			dfs(u,v);
// 		}
// 	}
// }
const ll mod = 1e9+7;
int main()
{
    //cout<<setprecision(12)<<fixed;
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 	
 	
    ll T;
    //cin>>T;
    T = 1;
    ll cas=1;
    while(T--)
    {
        //cout<<"Case #"<<cas<<": ";cas++;
        ll n;cin>>n;
        ll arr[n+1],sum[n+1];
        sum[0]=0;
        for(ll i=1;i<=n;i++){
            cin>>arr[i];
            sum[i]=(arr[i]+sum[i-1])%mod;
        }
        ll ans = 0;
        for(ll i=1;i<=n-1;i++){
            ll val = (sum[n]-sum[i]+mod)%mod;
            val = (arr[i]*val)%mod;
            ans = (ans+val)%mod;
        }

        cout<<ans<<endl;

    }
}
