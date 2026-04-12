#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define flash                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repc(i, a, b, c) for (ll i = a; (c > 0 ? i < b : i > b) and c != 0; i += c)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define all(name) (name.begin(), name.end())
#define fact(n) rep(i, 1, n + 1) ft.pb((ft[i - 1] * i) % mod);
#define mod_in(a) power(a, mod - 2)
#define ncr(n, r) ((ft[n] * mod_in((ft[r] * ft[(n) - (r)]) % mod)) % mod)
#define deb(x) cout << #x << " " << x << endl;
#define answ(x, y) cout << "Case #" << x << ": " << y << endl;
vector<bool> is_prime(10000, 1);
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

void sieve()
{
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= 10000; i++)
        if (is_prime[i])
            repc(j, i * i, 10000, i) is_prime[j] = 0;
}
// pair<ll, ll> d[mod];
// ll h[mod];
// vector<ll> edge[mod];

// void dfs(ll u, ll pair = -1)
// {
//     for (auto i : edge[u])
//     {
//         if (i == pair)
//             continue;
//         h[i] = h[u] + 1;
//         dfs(i, u);
//         d[u].first += d[i].first + 1;
//     }
// }

bool cmp(const pair<ll, ll> &c, const pair<ll, ll> &b)
{
    return c.first > b.first;
}
// ll power(ll x, ll y)
// {
//     ll res = 1;
//     x %= mod;
//     while (y > 0)
//     {
//         if (y & 1)
//             res = (res * x) % mod;
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return res % mod;
// }

// void bfs(int st,vector<ll> d){
//     queue<int> q;
//     d[st]=0;
//     q.push(st);
//     while(!q.empty()){
//         int v=q.front();
//         q.pop();
//         for(auto it:edge[v]){
//             if(d[it]==mod){
//                 d[it]=d[v]+1;
//                 q.push(it);
//             }
//         }
//     }
// }
//using namespace std;
// const ll man=1e5 +5;
// vector<ll> edge[man];
// vector<ll> dp(man);
// bool visited[man];
// ll coming[man];
// ll dfs(ll a){
//     if(edge[a].size()==0){
//         cout<<"a is "<<a<<endl;
//         return dp[a]=1;
//     }
//     visited[a]=1;
//     for(ll i=0;i<edge[a].size();i++){
//         cout<<"edge[a][i] is "<<edge[a][i]<<endl;
//         if(visited[edge[a][i]]==0){

//             dp[a]=max(dfs(edge[a][i])+1,dp[a]);
//         }
//     }
// }
// void dfs(ll a){
//     visited[a]=true;
//     for(auto b:edge[a]){
//         dp[b]=max(dp[b],dp[a]+1);
//         --coming[b];
//         if(coming[b]==0){
//             dfs(b);
//         }
//     }
// }
const ll man = 1e6;
vector<ll> edges[man];
vector<ll> visited(man, -1);

ll ans = 0;
void dfs(ll a, ll dist[])
{
    visited[a] = 1;
    if (edges[a].size() == 1)
    {
        if (visited[edges[a][0]] == 1)
        {

        }
        else
        {
            dist[edges[a][0]] = dist[a] + 1;
            dfs(edges[a][0], dist);
        }
    }
    for (auto v1 : edges[a])
    {
        if (visited[v1] == -1)
        {
            dist[v1] =dist[a] + 1;
            dfs(v1, dist);
        }
    }
}

int main()
{
    long long int i, j, k, o, n, m;
    cin >> n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    ll dp[n][n];
    for(ll l=n-1;l>=0;l--){
        for(ll r=l;r<n;r++){
            if(l==r){
                dp[l][r]=a[l];
            }
            else{
                dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}