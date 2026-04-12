#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 4000

ll dp[MAXN+1][MAXN+1];

int main(){
  int n;cin>>n;
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  bool f = n%2;
  rep(l, n)rep(i, n-l+1){

    // n奇数かつ今見ている長さが奇数なら先手番
    // n偶数かつ今見ている長さが偶数なら先手番
    bool isFirst = (f && !(l%2)) || (!f && (l%2));
    if(isFirst){
      dp[i][i+l] = max<ll>(dp[i][i+l-1] + a[i+l], dp[i+1][i+l] + a[i]);
    }else{
      dp[i][i+l] = min<ll>(dp[i][i+l-1] - a[i+l], dp[i+1][i+l] - a[i]);
    }
  }

  cout<<dp[0][n-1]<<endl;

  return 0;

  rep(i, n){
    rep(j, n)cout<<dp[i][j]<<' ';
    cout<<endl;
  }

  return 0;
}
