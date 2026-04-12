
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pii pair<int, int>
#define vpli vector<pair<long long, int>>
#define deb(x) cout << "deb " << #x << " " << x << endl
#define all(x) x.begin(), x.end()
#define endl "\n"
int cycle_len;
vi ord;

void dfs(int s,vi& vis,vvi &adj,int& tot)
{
    tot++;
    for(int x : adj[s])
    {
        if(!vis[x])
        {
            ord.pb(x);
            vis[x] = vis[s]+1;
            dfs(x,vis,adj,tot);
        }
        else
        {
            cycle_len = vis[s] - vis[x]+1;
            return;
        }
        
    }
}
void solve()
{
    int n;
    cin>>n;
    cout<<(n>=30?"Yes":"No")<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //pre();
    int t = 1;
    //cin >> t;
    //cout<<__gcd(-5,0)<<endl;
    while (t--)
        solve();
    return 0;
}
