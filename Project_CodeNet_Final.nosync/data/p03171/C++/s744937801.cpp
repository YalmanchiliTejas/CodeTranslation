#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 101010101000;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
ll dp[3010][3010];
int n;
vector<ll> a(3010);

int main(){
  cin >> n;
  rep(i,n) cin >> a[i];
  rep(i,n){
    rep(j,n){
      dp[i][j] = 0;
    }
  }
  for(int l=1;l<=n;l++){
    for(int i=0;i<=n-l;i++){
      if((n-l)%2==0) dp[i][i+l]=max(dp[i][i+l-1]+a[i+l-1],dp[i+1][i+l]+a[i]);
      if((n-l)%2==1) dp[i][i+l]=min(dp[i][i+l-1]-a[i+l-1],dp[i+1][i+l]-a[i]);
    }
  }
  cout << dp[0][n];
}