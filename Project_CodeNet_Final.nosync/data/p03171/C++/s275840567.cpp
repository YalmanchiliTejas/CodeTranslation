#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
typedef vector<vector<lli> > vvi;
typedef vector<ii> vii;
 
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

lli mod = 1e9 +7, inp[3010];
pair<lli, bool> dp[2][3010][3010];
int n;

lli solve(bool op, int l, int r)
{
    if(dp[op][l][r].SS==1)
        return dp[op][l][r].FF;
    dp[op][l][r].SS=1;
    if(l>r)
    	return 0;
    else if(op==0)
        dp[op][l][r].FF = max(inp[l]+solve(1, l+1, r), inp[r]+solve(1, l, r-1));
    else
        dp[op][l][r].FF = min(solve(0, l+1, r)-inp[l], solve(0, l, r-1)-inp[r]);
    return dp[op][l][r].FF;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> inp[i];
    cout<<solve(0, 1, n);
}