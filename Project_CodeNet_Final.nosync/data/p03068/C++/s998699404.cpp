#include "bits/stdc++.h"
using namespace std;
#define debug(var) cout << #var << ": " << var << endl;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
using ll = long long;
using ull = unsigned long long;
using vvint = vector<vector<int>>;
constexpr ll mod = 1e9 + 7;

int main() {

  int N; cin >> N;
  string S; cin >> S;
  int K; cin >> K;
  char c = S[K - 1];
  rep(i, N) {
	if (S[i] != c)cout << "*";
	else cout << c;
  }

  return 0;
}