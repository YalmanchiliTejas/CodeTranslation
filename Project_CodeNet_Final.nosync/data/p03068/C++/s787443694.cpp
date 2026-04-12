#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  for (int i=0; i<S.size(); i++) {
    if (S[i]!=S[K-1]) S[i] = '*';
  }
  cout << S << endl;
}