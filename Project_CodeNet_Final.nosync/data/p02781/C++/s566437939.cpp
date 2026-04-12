#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1001][2][4];

string NN;
ll KK;
int rec(int k = 0, bool tight = true, ll sum = 0){
    //cout<<k<<endl;
  if (sum > 3) {
    return 0;
  }
  if (k == NN.size()) {
    return sum == KK;
  }

  int x = NN[k] - '0';
  int r = (tight ? x : 9);

  ll &res  = dp[k][tight][sum];
  if (~res) return res;
  res = 0;

  for (int i = 0; i <= r; ++i) {
    res += rec(k + 1, tight && i == r, sum + (i == 0 ? 0 : 1));
  }
  return res;
}

void solve(string N, long long K){
    NN = N;
    KK = K;
    rec();
    /*
    for(int i = 0;i < NN.size();i++){
        for(int j = 0;j < K+1;j++){
            cout<<dp[i][1][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<dp[0][1][0]<<endl;
}

int main(){
    string N;
    cin >> N;
    long long K;
    scanf("%lld",&K);
    memset(dp, -1, sizeof(dp));

    solve(N, K);
    return 0;
}
