#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}

const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll dp[3005][3005];

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  rep(i,n) dp[i][i] = 0;
  
  for(int len = 1; len <= n; len++){
    for(int i = 0; i+ len <= n; i++){
      int j = i + len;
      
      if((n - len) % 2 == 0){
        dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1]+a[j-1]);
      }else{
        dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1]-a[j-1]);
      }
    }
  }
  
  cout << dp[0][n] << endl;

  return 0;
}