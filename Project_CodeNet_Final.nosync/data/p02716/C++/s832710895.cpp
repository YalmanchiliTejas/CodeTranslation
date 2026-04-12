//#define _GLIBCXX_DEBUG
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
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
template<class T> inline int add(T& a, T b, T M = MOD){if(a>=M)a%=M;if(b>=M)b%=M;a+=b;if(a>=M)a%=M;return a;};
template<class T> inline int mul(T& a, T b, T M = MOD){if(a>=M)a%=M;if(b>=M)b%=M;a*=b;if(a>=M)a%=M;return a;};
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n, a[210000], b[210000];
int dp[210000][3];
signed main(){
  cin>>n;rep(i,n)cin>>a[i];
  if(n % 2 == 0){
    int odd = a[1], even = a[0];
    b[0] = a[0];b[1] = a[1];
    repd(i,2,n){
      if(i % 2 == 0){
        even += a[i];
        b[i] += b[i-2] + a[i];
      }else{
        odd += a[i];
        b[i] += b[i-2] + a[i];
      }
    }
    int ans = max(odd, even);
    rep(i,n){
      if(i % 2 == 0)continue;
      chmax(ans, b[i-1] + b[n-1] - b[i]);
    }
    cout << ans << endl;
  }else{
    dp[0][0] = a[0];dp[1][1] = a[1];dp[2][0] = a[0]+a[2];dp[2][2] = a[2];
    repd(i,3,n){
      dp[i][0] = dp[i-2][0] + a[i];
      dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + a[i];
      dp[i][2] = max(dp[i-2][2], dp[i-3][1]) + a[i];
    }
    cout << max({dp[n-1][2], dp[n-2][1]}) << endl;
  }
}
