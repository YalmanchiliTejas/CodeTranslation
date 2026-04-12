#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100100;

int a[200010];
int dp[200010][3];
signed main(){
  int n;cin>>n;
  int m=n/2;
  rep(i,n)cin>>a[i];
  for(int i=1;i<=m;i++){
    rep(j,3){
      int ans=-INF;
      rep(k,j+1){
        ans=max(ans,dp[i-1][k]+a[2*(i-1)+k]);
      }
      dp[i][j]=ans;
    }
  }
        
  cout<<dp[m][n-(2*m-1)]<<endl;    
  
  return 0;
}