#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mx INT_MAX
#define mn INT_MIN
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define itr set<int> :: iterator
const int N = 1e5+10;

vector<ll> a;
ll dp[3001][3001][2];

ll solve(int i, int j, int flag){

  if(i>j)
    return 0;

  if(dp[i][j][flag]!= -1){
    return dp[i][j][flag];
  }
  
  if(flag == 1){
    dp[i][j][flag] = max(a[i]+solve(i+1, j, 0), a[j]+solve(i,j-1, 0));
  }else
    dp[i][j][flag] = min(solve(i+1, j, 1), solve(i, j-1, 1));

   return dp[i][j][flag];
}

int main(){

  // **** START HERE ****
       
   int n;
   cin>>n;

   a.clear();
   ll sum = 0;
   for(int i=0; i<n; i++){
    ll x;
    cin>>x;
    sum += x;
    a.pb(x);
   }
   
   memset(dp, -1, sizeof(dp));

   ll res = solve(0, n-1, 1);
   ll y = sum - res;
   cout<<res-y<<endl;

  // **** END HERE ****
    
    return 0;
}