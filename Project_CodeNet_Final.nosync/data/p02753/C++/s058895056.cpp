#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s[0] == s[1] && s[0] == s[2] && s[1] == s[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
}