#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

ll ans = 0;

int main(){
  string S; cin >> S;
  int N = sz(S);
  int K; cin >> K;
  /*
  dp[i][j][k]
  i: 頭からi桁 j: 未満フラグ k: 0以外の個数
  dp[i][0][0]:頭からi桁 n未満確定 全部0
  dp[i][0][1]:頭からi桁 n未満確定 0以外が1個
  dp[i][1][0]:頭からi桁 nは一致 全部0
  dp[i][1][1]:頭からi桁 nは一致 0以外が1個
  */
  vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(2,vector<ll>(K+2,0)));
  dp[0][0][0] = 1;
  rep(i,N){
    rep(smaller,2){
      rep(k,K+1){
        for(int x=0; x<=(smaller?9:(int)(S[i]-'0')); x++){
          dp[i + 1][smaller || x < (int)(S[i]-'0')][k+(x!=0)] += dp[i][smaller][k];
        }
      }
    }
  }
  cout << dp[N][0][K] + dp[N][1][K] << endl;
  return 0;
}
