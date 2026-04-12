#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  string S; cin >> S;
  string result = "No";
  rep(i,S.length()-1) if (S[i]=='A'&&S[i+1]=='C') result = "Yes";
  cout << result << endl;
  return 0;
}