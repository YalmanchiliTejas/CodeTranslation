#include <bits/stdc++.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define nui 100
#define INF 100000000000
 
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf int t;cin>>t;for(int w=1;w<=t;w++)
 
 
 
using namespace std;
 
 
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
 
ll fermat_inv(ll y) {return binpow(y, mod - 2);}
 
/*vector<ll>adj[100001];
vector<bool>visited(100001, 0);
vector<ll>parent(100001, 0);
vector<ll>a(100001, 0);
 
void dfs(ll node)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i);
            a[node] += a[i];
            parent[i] = node;
        }
    }
}*/
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    ll x;
    cin>>x;
    if(x>=30)
    {
        cout<<"Yes\n";
    }
    else
    {

        cout<<"No\n";
    }
 
    return 0;
 
 
 
 
 
}
 
 
 