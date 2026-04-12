#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string S;
  cin >> S;
  bool possible = false;
  for (int i=0; i<S.size()-1; i++) {
    if (S[i]=='A'&&S[i+1]=='C') {
      possible = true;
      break;
    }
  }
  if (possible) cout << "Yes" << endl;
  else cout << "No" << endl;
}