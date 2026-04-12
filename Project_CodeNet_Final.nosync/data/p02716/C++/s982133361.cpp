#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=1000000;
const ll inf=1e9;
const ll mod=998244353;


int R[MX];
ll dp[MX][3][2][3][2], n;

ll call(int p, int a, int b, int x, int y)
{
    if(p>n) return 0;
    if(~dp[p][a][b][x][y]) return dp[p][a][b][x][y];

    ll sm=R[p]+call(p+2, a, b, x, y);
    if(x && a<x && !b) sm=max(sm, R[p]+call(p+3, a+1, b, x, y));
    if(y && b<y && x && !a) sm=max(sm, R[p]+call(p+4, a, b+1, x, y));
    return dp[p][a][b][x][y]=sm;
}

int main()
{
    FasterIO;

    cin>>n;
    for(int i=1; i<=n; i++) cin>>R[i];

    mem(dp, -1);
    ll sm;
    if(n&1) sm=max({call(1, 0, 0, 2, 1), call(2, 0, 0, 1, 0), call(3, 0, 0, 0, 0)});
    else    sm=max(call(1, 0, 0, 1, 0), call(2, 0, 0, 0, 0));
    cout<<sm<<endl;

    return 0;
}
