#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;

int a[6010];
int dp[2010][2010];
int maxa[2010]; //要素にiを持つ場合の最大値

int const inf = 1e9;

int main(){
  int n;
  cin >> n;
  int n3 = n*3;
  
  rep(i,n3) cin >> a[i],--a[i];
  rep(i,n)rep(j,n) dp[i][j] = -inf;
  rep(i,n) maxa[i] = -inf;
  

  dp[a[0]][a[1]] = 0;
  dp[a[1]][a[0]] = 0;
  maxa[a[0]] = maxa[a[1]] = 0;
  int maxab = 0; //その時点での最大値
  int ex = 0;
    
  for(int i=2; i < n3-2; i+=3){
    int x = a[i];
    int y = a[i+1];
    int z = a[i+2];
    
    //新しい3枚が一致していたとき
    if(x == y && y == z){ 
      ++ex;
      continue;
    }
    
    vector<T> upd;

    rep(j,3){
      //古い2枚と新しい1枚
      //古いのを2枚捨てるからその時点の最大値maxabと比較。
      int m = max(maxab, dp[z][z]+1);
      upd.emplace_back(x,y,m);
      
      //古い1枚と新しい2枚
      //古いものを1枚捨てる
      rep(k,n){
        int m = maxa[k];
        if(x == y) m = max(m, dp[x][k]+1);
        upd.emplace_back(z,k,m);
      }
      swap(x,y); swap(y,z);
      
    }

    for(auto t : upd){
      int na, nb, s;
      tie(na, nb, s) = t;
      
      dp[na][nb] = max(dp[na][nb], s);
      dp[nb][na] = max(dp[nb][na], s);
      maxa[na] = max(maxa[na], s);
      maxa[nb] = max(maxa[nb], s);

      maxab = max(maxab, s);
    }   
  }
  
  int ans = maxab;
  int al = a[n3-1];
  ans = max(ans, dp[al][al]+1);
  ans += ex;
  cout << ans << endl;

  return 0;
}