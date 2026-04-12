#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int MOD = 1000000007;
int INF = numeric_limits<int>::max() / 10;


signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int N;
  cin >> N;
  string S[N];
  rep(i, N) cin >> S[i];
  int A[N][26] = {};
  rep(i, N){
    rep(j, S[i].size()){
      A[i][S[i][j] - 'a']++;
    }
  }
  string ans{};
  rep(i, 26){
    int num = INF;
    rep(j, N){
      num = min(num, A[j][i]);
    }
    rep(j, num){
      ans += 'a' + i;
    }
  }
  cout << ans <<endl;

}