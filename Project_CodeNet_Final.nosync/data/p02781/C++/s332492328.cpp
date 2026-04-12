#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
  string N; cin >> N;
  ll n = N.size();
  ll K; cin >> K;
  ll dp[105][4][2];
  rep(i, 105)rep(j, 4)rep(k, 2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  rep(i, n)rep(j, 4)rep(k, 2){
    ll nd = ctoi(N[i]);
    rep(d, 10){//dは次に追加する数
      ll ni = i +1, nj = j, nk = k;
      if (d != 0) nj++;//dが0でないならjを1増やす
      if (nj > K) continue;
      if (k == 0){//smaller flagがたっていないとき
        if (d > nd) continue;//dの値が今の桁の数より大きいならばなにもしない
        if (d < nd) nk = 1;//dの値が今の桁の数未満ならばsmaller flagを立てる
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  ll ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
}