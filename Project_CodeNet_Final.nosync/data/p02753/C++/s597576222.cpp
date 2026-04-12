#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const string YES = "Yes";
const string NO = "No";
int main(){
  string S; cin >> S;
  if (S[0] == S[1] && S[1] == S[2]) cout << NO << endl;
  else cout << YES << endl;
}
