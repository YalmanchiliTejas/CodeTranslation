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
int dp[2][N];
int a[N];
int n;

void solve()
{
   cin >> n;
    
   f(i,n) cin >> a[i];
    
   for(int i=1;i<=n;i++)
     for(int j=0;j<n-i+1;j++)
          dp[i%2][j] = max(-dp[(i-1)%2][j]+a[j+i-1],-dp[(i-1)%2][j+1]+a[j]);  
       
   cout << dp[n%2][0] << '\n'; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}