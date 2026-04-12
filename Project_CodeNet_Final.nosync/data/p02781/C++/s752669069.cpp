#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

string n;int k;
vector<int> vec;
int dp[200][2][10];
signed main(){
  cin>>n>>k;
  rep(i,n.length()){
    vec.push_back((int)(n[i]-'0'));
  }
  dp[0][1][0] = 1LL;
  rep(i,n.length()){
    rep(j,k+1){
      (vec[i] == 0 ? dp[i+1][1][j] : dp[i+1][1][j+1]) += dp[i][1][j];
      dp[i+1][0][j+1] += dp[i][0][j]*9 + dp[i][1][j]*max(0LL,vec[i]-1);
      dp[i+1][0][j] += dp[i][1][j]*(vec[i] > 0) + dp[i][0][j];
    }
  }
  cout << dp[n.length()][1][k] + dp[n.length()][0][k] << endl;
}
