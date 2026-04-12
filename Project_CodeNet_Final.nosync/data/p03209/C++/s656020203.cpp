#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long ll;
const int MAX_N = 51;
ll layers[MAX_N];
ll patty[MAX_N];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll N, X;
  cin >> N >> X;

  layers[0] = 1;
  for (int i = 1; i <= MAX_N; i++) {
    layers[i] = layers[i - 1]*2 + 3;
  }

  patty[0] = 1;
  for (int i = 1; i <= MAX_N; i++) {
    patty[i] = patty[i-1] * 2 + 1;
  }

  ll total = 0;
  
  while (N > 0) {
      
    ll n_layers = layers[N];
    ll mid = n_layers/2 + 1;

    if (X == 1) {
      cout << total << endl;
      return 0;
    }
    if (1 < X && X < mid) {
      if (N == 1) {
	total += 1;
      } else {
      	X--;
      }
      
    }
    else if (X == mid) {
      total += patty[N-1];
      total += 1;
      cout << total << endl;
      return 0;
    }
    else if (mid < X && X < n_layers) {
      if (N == 1) {
	total += 3;
      } else {
	total += patty[N-1];
	total += 1;
	X -= (layers[N-1] + 2);
      }
    }
    else if (X == n_layers){
      total += patty[N];
      cout << total << endl;
      return 0;
    }
    
    N--;
  }

  cout << total << endl;
  return 0;
}

