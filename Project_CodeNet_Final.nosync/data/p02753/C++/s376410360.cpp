#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < (n); ++i )
#define rep_rev(n,i) for(ll i = n; i >= 0; --i )
using namespace std;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
  string S; cin >> S;
  if(S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
