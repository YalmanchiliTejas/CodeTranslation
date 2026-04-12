#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define pb emplace_back
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define rep(i, j, k) for(i=j; i<k; i++)
#define sep(i, j, k) for(i=j; i>k; i--)
const int N = 2e4+5, inf = 1e9+7;
int n, k, i, j;
int A[N], dp[N][2][101], d;
string v;

int dfs(int id, int is, int rem){
    if(id==sz(v)) return (rem==0);
    int& ans = dp[id][is][rem], lim;
    if(ans!=-1) return ans;
    ans = 0;
    if(is) lim = 9;
    else lim = v[id]-'0';
    for(int i=0; i<=lim; i++) ans += dfs(id+1, is|(i<v[id]-'0'), (rem+i)%d);
    return ans%=inf;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j, a, b, ans = 0;
    cin>>v>>d;
    memset(dp, -1, sizeof dp);
    cout<<(dfs(0, 0, 0)+inf-1)%inf;
}