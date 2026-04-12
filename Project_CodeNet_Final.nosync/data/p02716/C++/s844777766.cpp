#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll dp[200005][3][2];

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
  }
  rep(i, 200005){
    rep(j, 3){
      rep(k, 2){
        dp[i][j][k]=-INFll;
      }
    }
  }
  dp[0][1][0]=0;
  repo(i, n){
    rep(j, 3){
      rep(k, 2){
        if((i-1)/2-1+j>=i/2-1 &&(i-1)/2-1+j<=(i+1)/2){
          dp[i][(i-1)/2-1+j-(i/2-1)][0]=max(dp[i][(i-1)/2-1+j-(i/2-1)][0], dp[i-1][j][k]);
        }
        if((i-1)/2-1+j+1>=i/2-1 &&(i-1)/2-1+j+1<=(i+1)/2 && k==0){
          dp[i][(i-1)/2-1+j+1-(i/2-1)][1]=max(dp[i][(i-1)/2-1+j+1-(i/2-1)][1], dp[i-1][j][k]+a[i-1]);
        }
      }
    }
  }
  ll ans=max(dp[n][1][0], dp[n][1][1]);
  cout << ans << endl;
  return 0;
}
