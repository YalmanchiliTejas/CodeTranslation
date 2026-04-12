#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,29)-1;


int main() {
  int N; cin >> N;
  string S; cin >> S;
  int K; cin >> K;

  string result = "";
  rep(i,N) result += (S[i]==S[K-1]) ? S[K-1] : '*';
  cout << result << endl;
  return 0;
}