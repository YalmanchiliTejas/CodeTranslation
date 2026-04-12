#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define _GLIBCXX_DEBUG
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main() {
  string s;cin >> s;
  if(s[0] == s[1]&&s[1] == s[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
}