#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;



int main() {
  string S;
  cin >> S;
  if(S[1]!=S[0]||S[1]!=S[2])cout << "Yes";
  else cout << "No";
}