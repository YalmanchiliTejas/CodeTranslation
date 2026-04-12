#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,k;int a[3100];
int dp[3100][3100];
int r[3100];
int sum(int i, int j){
  return r[j] - r[i];
}
int rec(int i, int j){
  if(dp[i][j] != -1)return dp[i][j];
  if(i == j)return dp[i][j] = 0;
  dp[i][j] = max(sum(i+1, j) - rec(i+1, j)+a[i], sum(i, j-1) - rec(i,j-1)+a[j-1]);
  return dp[i][j];
}
signed main(){
  cin>>n;rep(i,n)cin>>a[i];
  rep(i,n)r[i+1] = r[i]+a[i];
  rep(i,3100)rep(j,3100)dp[i][j] = -1;
  rec(0, n);
  cout << dp[0][n]*2 - sum(0, n) << endl;
}
