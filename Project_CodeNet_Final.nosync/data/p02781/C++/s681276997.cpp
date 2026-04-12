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

string S;
int K;
ll DP1[105][105], DP2[105][105];

int main(){
  cin >> S >> K;

  int N = S.length();
  DP1[0][0] = 1; DP1[0][1] = S[0] - '1';
  DP2[0][1] = 1;

  for (int i = 1; i < N; i++){
    ll now = S[i] - '0';
    if (now == 0){
      for (int j = 0; j <= K; j++){
        DP2[i][j] = DP2[i-1][j];
        DP1[i][j] += DP1[i-1][j];
        DP1[i][j+1] += DP1[i-1][j] * 9;
      }
      continue;
    }

    for (int j = 0; j <= K; j++){
      DP2[i][j+1] = DP2[i-1][j];
      DP1[i][j] += DP1[i-1][j];
      DP1[i][j+1] += DP1[i-1][j] * 9;
      DP1[i][j] += DP2[i-1][j];
      DP1[i][j+1] += DP2[i-1][j] * (now - 1); 
    }
  }

  cout << DP1[N-1][K] + DP2[N-1][K] << endl;
  return 0;
}
