/*
    author: kartik8800
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x 
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll dp[3001][3001][2];
ll solve(vector<int>& v, int i, int j, bool turn)
{
    if(i > j)
        return 0;
    
    if(dp[i][j][turn] != -1)
        return dp[i][j][turn];
    
    if(turn == 1)
        return dp[i][j][turn] = max(v[i] + solve(v, i+1,j,0), v[j] + solve(v, i,j-1, 0));
    else return dp[i][j][turn] = min(solve(v, i+1,j,1)-v[i], solve(v, i,j-1, 1)-v[j]);
}

int main() {
   int n;
   cin >> n ;
   vector<int> v(n+1);
   memset(dp, -1, sizeof dp);
   ll sum = 0;
   for(int i = 1; i <= n; i++)
    {
        cin>>v[i];
        sum += v[i];
    }
   ll scoreX = solve(v, 1, n, 1);
   ll scoreY = (sum - scoreX);
   cout << scoreX;
   return 0;
}
