/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod   1000000000
#define PI 2*acos(0.0)
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};

ll bigmod(ll x, ll p)
{
    ll res = 1;
    while(p)
    {
        if(p&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        p >>= 1;
    }
    return res;
}



//=============================================ASIFAZAD==============================================//

const int N = 100010;
int n, p;
vll ppl(N), vis(N), good(N) , h(N);
vector<vi> adj;
bool ans = true;

void dfs(int par, int pp)
{
    vis[par] = ppl[par];
    ll totg = 0;

    for(auto x: adj[par])
    {
        if(x == pp)
            continue;

        dfs(x, par);
        vis[par] += vis[x];
        totg += good[x];

    }

    ll ck = (vis[par] + h[par]);
    if(ck < 0 || ck%2 != 0 || ck/2 > vis[par])
        ans = 0;
    if(totg > ck/2)
        ans = 0;
    if(!ans)
        return;
    good[par] = ck/2;

}


int32_t main()
{
    io;
    int x;
    cin >>x;
    cout<<(x >= 30?"Yes":"No");
    return 0;
}