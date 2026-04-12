#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  string T, P;
 
  cin >> T;
  cin >> P;
 
  vector< int > latte[26];
  for(int i = 0; i < T.size(); i++) {
    latte[T[i] - 'a'].push_back(i);
  }
 
  vector< int > beet(P.size(), -1);
  int last = 0;
  for(int i = 0; i < P.size(); i++) {
    auto &p = latte[P[i] - 'a'];
    auto q = lower_bound(begin(p), end(p), last);
    if(end(p) == q) {
      cout << "no" << endl;
      return (0);
    }
    beet[i] = *q;
    last = *q + 1;
  }
 
  last = T.size() - 1;
  for(int i = P.size() - 1; i >= 0; i--) {
    auto &p = latte[P[i] - 'a'];
    auto q = upper_bound(begin(p), end(p), last);
 
    if(begin(p) == q) {
      cout << "no" << endl;
      return (0);
    }
    --q;
 
    if(beet[i] != *q) {
      cout << "no" << endl;
      return (0);
    }
    last = *q - 1;
  }
 
  cout << "yes" << endl;
 
}