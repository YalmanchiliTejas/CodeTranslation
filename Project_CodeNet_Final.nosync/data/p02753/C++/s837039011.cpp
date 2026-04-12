
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;
void YesNo(bool j){cout << (j ? "Yes" : "No") << endl; return;}
void yesno(bool j){cout << (j ? "yes" : "no") << endl; return;}
template<class Head> void pt(Head&& head){cout << head << endl; return;}



int main() {
  bool ok=true;
  string s;
  cin >> s;
  if(s=="AAA" || s=="BBB") ok=false;
  YesNo(ok);
  return 0;
}
