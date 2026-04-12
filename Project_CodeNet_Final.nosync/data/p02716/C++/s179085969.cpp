#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define for(i,a,b) for(ll i=a;i<b;i++)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n;
  cin >> n;
  vl a(n);
  for(i,0,n){
    cin >> a[i];
  }
  vvl dp(n,vl(3));
  for(i,0,n){
    for(j,0,3){
      dp[i][j]=-INF;
    }
  }
  dp[0][0]=a[0];
  dp[1][1]=a[1];
  if(n>=3){
  dp[2][2]=a[2];
    if(n>=4){
  dp[3][1]=max(dp[0][0],dp[1][1])+a[3];
    }
  dp[2][0]=a[0]+a[2];
    }
  if(n>4){
  	for(i,4,n){
   	 if(i%2==0){
      dp[i][0]=dp[i-2][0]+a[i];
      }
 	   dp[i][1]=max(dp[i-2][1]+a[i],a[i]+dp[i-3][0]);
 	   dp[i][2]=max(dp[i-2][2]+a[i],max(dp[i-3][1],dp[i-4][0])+a[i]);
 	 }
  }
  if(n%2==0)
    cout << max(dp[n-2][0],dp[n-1][1]) << endl;
  else
    cout << max(max(dp[n-1][2],dp[n-2][1]),dp[n-3][0]) << endl;
}
