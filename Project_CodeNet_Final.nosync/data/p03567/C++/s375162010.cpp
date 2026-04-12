#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  string S; cin >>S;
  string ans="No";
  rep(i,1,S.size()) {
    if (S[i-1]=='A' && S[i]=='C') {
      ans="Yes";
      break;
    }
  }
  cout <<ans <<endl;
  return 0;
}
