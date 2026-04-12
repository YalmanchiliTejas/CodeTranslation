#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

string S; int N, K;
ll DP1[105][4], DP2[105][4];

int main(){
  cin >> S >> K;
  N = S.length();

  DP2[0][0] = 1;

  for (int i = 1; i <= N; i++){
    for (int j = 0; j <= K; j++){
      DP1[i][j] += DP1[i-1][j];
      DP1[i][j] %= MOD;
    }
    for (int j = 0; j < K; j++){
      DP1[i][j+1] += DP1[i-1][j] * 9;
      DP1[i][j+1] %= MOD;
    }

    if (S[i-1] == '0'){
      for (int j = 0; j <= K; j++){
        DP2[i][j] = DP2[i-1][j];
      }
    }else{
      ll num = S[i-1] - '1';
      for (int j = 0; j <= K; j++){
        DP1[i][j] += DP2[i-1][j]; DP1[i][j] %= MOD;
      }
      for (int j = 0; j < K; j++){
        DP1[i][j+1] += DP2[i-1][j] * num;
        DP1[i][j+1] %= MOD;
        DP2[i][j+1] = DP2[i-1][j];
      }
    }
  }

  cout << (DP1[N][K] + DP2[N][K]) % MOD << endl;

  return 0;
}
