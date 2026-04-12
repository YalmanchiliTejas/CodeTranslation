#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define SUM(n) ((n)+1)*(n)/2
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD=int(1e9)+7;

using namespace std;

string n;
int k;
int dp[100][2][5];
 
lol rec(int i = 0,bool tight = true,lol sum = 0){
  
  if(i==n.size()){ return (sum == k); }
  if(dp[i][tight][sum] != -1){ return dp[i][tight][sum]; }
  if(sum>k){ return 0; }
 
  int lim = ( tight ? n[i]-'0' : 9 );
 
  int ret = 0;
  ret+=rec(i+1,tight && (lim == 0),sum);
  for(int d=1;d<=lim;d++){
    ret+=rec(i+1,tight && (lim == d),sum+1);
  }
  return dp[i][tight][sum] = ret;
}
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  cin>>n>>k;
  memset(dp,-1,sizeof(dp));
  cout<<rec()<<'\n';
 
  return 0;
}
