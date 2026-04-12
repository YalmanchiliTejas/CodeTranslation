#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

vvl dp(3010,vl(3010));
vvb seen(3010,vb(3010,false));

long dfs(vl &a, int i, int j, bool taro){
  if(seen[i][j]) return dp[i][j];
  seen[i][j] = true;
  if(i == j){
    if(taro) return dp[i][j] = a[i];
    else return dp[i][j] = -1*a[i];
  }
  if(taro){
    return dp[i][j] = max(dfs(a,i+1,j,!taro) + a[i], dfs(a,i,j-1,!taro) + a[j]);
  }else{
    return dp[i][j] = min(dfs(a,i+1,j,!taro) - a[i], dfs(a,i,j-1,!taro) - a[j]);
  }
}

int main(){
  int n;
  cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];
  cout << dfs(a, 0, n-1, true) << endl;
}