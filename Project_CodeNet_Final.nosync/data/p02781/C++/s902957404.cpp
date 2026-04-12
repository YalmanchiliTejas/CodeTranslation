#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

ll dp[510][5][2];
//dp[i][j][k] は　iけためまでで　jこ0でない数存在している k = 0は未満確定　時の個数

int main(){
  string s; cin >> s;
  ll K; cin >> K;
  ll N = s.size();

  // 上のくらいから順番に追っていく
  dp[0][0][1] = 1;
  rep(i,N){
    ll d = s[i] - '0';
    rep(j,K + 1){
      // 元から未満確定　と　今確定
      if(d == 0){
        // 元から未満確定
        dp[i + 1][j + 1][0] += dp[i][j][0] * 9;
        // 0を選ぶ
        dp[i + 1][j][0] += dp[i][j][0];

        // まだ同じ可能性
        dp[i + 1][j][1] += dp[i][j][1];
      }
      else{
        // 元から未満確定　と　今確定
        dp[i + 1][j + 1][0] += dp[i][j][0] * 9 + dp[i][j][1] * (d - 1);
        // まだ同じ可能性
        dp[i + 1][j + 1][1] += dp[i][j][1];
        // 0を選べば j は増えない　、未満が確定する
        dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
      }
    }
  }
  
  cout << dp[N][K][0] + dp[N][K][1] << endl;
}
