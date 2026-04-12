#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 3002;
int dp[N][N][2];
int a[N];
int n;

int get(int i,int j,int k)
{
    if(i>j) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    int a1 = -get(i+1,j,k^1) + a[i];
    int a2 = -get(i,j-1,k^1) + a[j];
    
    return dp[i][j][k] = max(a1,a2);
}

void solve()
{
   memset(dp,-1,sizeof(dp)); 
    
   cin >> n;
    
   f(i,n) cin >> a[i];
    
   cout << get(0,n-1,0) << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}