#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long 
#define pb push_back
#define fo(i,N) for(int i = 0 ; i < N ; i++)
#define foo(i,x,N) for (int i = x; i < N ; i++)
#define fill(a,val) memset(a,val,sizeof(a))
#define fastio()  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ff first
#define ss second
#define MAX 1234567
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define inf 1e14+1
#define all(a) a.begin(),a.end()
string s;
ll dp[100001][101][2];
int D;

ll solve(int pos,int d,int tight)
{  
   if ( dp[pos][d][tight] != -1)
   {
    return dp[pos][d][tight];
   }
   
   int m = (tight) ? (int)(s[pos]-'0') : 9;
   if ( pos == s.length()-1)
   {
    ll ans = 0;

    fo(x,m+1)
    {
      if (x%D == d)
        ans++;
    }
    return ans;
   }

   ll ans = 0;

   fo(x,m+1)
   {
    ans = (ans + solve(pos+1,(D+d-(x%D))%D,(tight&&(x==m))))%M;
   }
   return dp[pos][d][tight] = ans;
   

}

int main()
{ 
  cin >> s;
  cin >> D;
  fill(dp,-1);

  cout << (M-1+solve(0,0,1))%M;
 
}