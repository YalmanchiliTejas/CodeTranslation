#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  string s;
  cin >> s;
  set<char> c;
  for(ll i=0;i<3;i++) {
    c.insert(s[i]);
  }
  if(c.size()==2) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}