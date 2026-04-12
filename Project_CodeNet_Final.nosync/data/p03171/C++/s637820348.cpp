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
#define inf 1e9+1
#define all(a) a.begin(),a.end()


vector <int> p(3001);
int n,k;
ll dp[3001][3001];

ll solve(int i,int j)
{
   if ( i > j )
    return 0;

   if (dp[i][j] != -1)
    return dp[i][j];

   ll op1 = p[i] + min(solve(i+2,j),solve(i+1,j-1));
   ll op2 = p[j] + min(solve(i,j-2),solve(i+1,j-1));

   return dp[i][j] = max(op1,op2);
 



}

int main()
{  
   cin >> n;
   ll tot = 0;
   fo(i,n)
   { 
    cin >> p[i];
    tot += p[i];
   }
  fill(dp,-1);


  cout << 1ll*2*solve(0,n-1)-tot << endl;
  
}

