#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;
 
string S;
 
int main(void) {
  cin >> S;
 
  REP(i, 0, S.length() - 1) {
    if(S[i] == 'A' && S[i + 1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}