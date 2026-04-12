#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 2e5 + 10;
int dp[N];

void solve()
{
   int n,x,m;
    cin >> n >> x >> m;
    
   if(m == 1)
   {
       cout << 0 << '\n';
       return;
   }
    
   dp[1] = x;
   for(int i=2;i<N;i++) dp[i] = (dp[i-1]*dp[i-1])%m;
    
   int res = 0; 
    
   if(n < N)
   {
       for(int i=1;i<=n;i++) res+=dp[i];
   }
   else
   {
       map<int,int> save;
       
       for(int i=1;i<N;i++)
       {
          if(save.find(dp[i]) == save.end())
          {
              save[dp[i]] = i;
              res+=dp[i];
          }
          else
          {
              int st = save[dp[i]];
              int len = i - st;
              n-=i-1;
              
              int full = (n/len);
              int partial = (n % len);
              
              for(int j=st;j<i;j++)
              {
                  res+=full*dp[j];
                  
                  if(partial > 0) 
                  {
                      res+=dp[j];
                      partial--;
                  }
              }
              
              break;
          }
       }
   }
    
   cout << res; 
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}