#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vvi vector<vector<int>> 
#define vi vector<int> 
#define vpii vector<pair<int,int>> 
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define ffor(i,n) for(int i = 0; i < n; ++i)

vi a;
int n;
vvi dp;

int solve(int l,int r)
{
    if(l == r) return a[l];
    if(r == l + 1) return max(a[l],a[r]);
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = max(a[l] + min(solve(l + 1,r - 1),solve(l + 2,r)),a[r] + min(solve(l,r - 2),solve(l + 1,r - 1)));
    return dp[l][r];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    ffor(i,n) cin >> a[i];
    dp.resize(n,vi(n,-1));
    int x = solve(0,n - 1);
    int y = accumulate(all(a),0LL);
    int z = y - x;
    cout << (x - z);
}