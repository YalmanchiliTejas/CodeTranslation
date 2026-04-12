#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 55;

ll N, X;

ll layers[MAX];
ll patty[MAX];

ll solve(ll n, ll k) { // レベルnバーガーのk層目までのパティの数
  if (n == 0) return 1;
  if (k == 1) return 0;
  if (k <= layers[n-1]+1) return solve(n-1, k-1);
  if (k == layers[n-1]+2) return patty[n-1]+1;
  if (k <= 2*layers[n-1]+2) return patty[n-1]+solve(n-1, k-2-layers[n-1])+1;
  return patty[n];
}

int main() {

  cin >> N >> X;

  layers[0] = 1;
  patty[0] = 1;
  for (int i = 1; i <= N; i++) {
    layers[i] = layers[i-1]*2+3;
    patty[i] = patty[i-1]*2+1;
  }

  cout << solve(N, X) << endl;
}