#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  string s;
  cin >> s;
  set<char> c;
  for(auto i:s) {
    c.insert(i);
  }
  if(c.size()==2) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}