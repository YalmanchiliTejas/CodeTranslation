#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

string T, P;

int main(void) {
  cin >> T >> P;

  vector<ll> first;
  {
    ll j = 0;
    REP(i, 0, P.length()) {
      while(j < T.length() && T[j] != P[i]) j++;
      if(j == T.length()) {
        cout << "no" << endl;
        return 0;
      }
      first.push_back(j);
      j++;
    }
    // REP(i, 0, first.size()) cout << first[i] << " ";
    // cout << endl;
  }

  vector<ll> last;
  {
    ll j = T.length() - 1;
    for(ll i = P.length() - 1; i >= 0; i--) {
      while(j >= 0 && T[j] != P[i]) j--;
      if(j == -1) {
        cout << "no" << endl;
        return 0;
      }
      last.push_back(j);
      j--;
    }
    reverse(last.begin(), last.end());
    // REP(i, 0, last.size()) cout << last[i] << " ";
    // cout << endl;
  }

  ll ans = 1;
  REP(i, 0, first.size()) ans = ans && first[i] == last[i];
  cout << (ans ? "yes" : "no") << endl;
}