#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K,typename V>
using umap = unordered_map<K,V>;
template <typename V>
using uset = unordered_set<V>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(v) v.begin(),v.end()

#define endl "\n"
#define INF 1'000'000'000'000 //10^12
#define MOD 1'000'000'007
//グリッドグラフの範囲チェック
bool range_validation(int y,int x,int h,int w){
    return y>=0 && y<h && x>=0 && x < w;
}
//ビットカウント
int popcount(long bits){
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int gcd(ll a, ll b){
  if(b == 0){
    return a;
  }else{
    return gcd(b,a%b);
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  int a[n];
  REP(i,n) cin >> a[i];

  // dp[i][j] := a[i]からa[j]まで残った状態から始まった時の得点
  vector<vector<ll>> dp(n,vector<ll>(n));

  REP(i,n){
    if((n-1)%2==0){
      dp[i][i] = a[i];
    }else{
      dp[i][i] = -a[i];
    }
  }

  FOR(dif,1,n){
    REP(j,n){
      if(j+dif >= n)break;

      //とった数が偶数なら先手の番
      if((n-dif-1)%2==0){
        dp[j][j+dif] = max(dp[j+1][j+dif] + a[j] , dp[j][j+dif-1] + a[j+dif]);
      }else{
        dp[j][j+dif] = min(dp[j+1][j+dif] - a[j] , dp[j][j+dif-1] - a[j+dif]);
      }
    }
  
  }

  cout << dp[0][n-1] << endl;
  return 0;
}
