#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long MOD = 1000000007;

string ar;
int n, k;
ll dp[10002][101][2][2];
ll F(int pos, int sum, int started, int choto){
  if (pos >= n){
    if (sum % k == 0 && started){
      return 1;
    }
    return 0;
  }
  if (dp[pos][sum][started][choto] != -1){
    return dp[pos][sum][started][choto];
  }
  ll res = 0;
  if (choto){
    for (int i = 0; i <= 9; i++){
      res = (res % MOD + F(pos + 1, (sum + i) % k, !(started == 0 && i == 0), choto) % MOD) % MOD;
    }
  }
  else {
    for (int i = 0; i <= ar[pos] - '0'; i++){
      res =  (res % MOD + F(pos + 1, (sum + i) % k, !(started == 0 && i == 0), (i < ar[pos] - '0')) % MOD) % MOD;
    }
  }
  return dp[pos][sum][started][choto] = res % MOD;
}

int main(){
  memset(dp, -1, sizeof(dp));
  cin >> ar >> k;
  n = ar.size();
  cout << F(0, 0, 0, 0) << '\n';
  return 0;
}
