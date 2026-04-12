#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main(){
  string s;
  cin >> s;
  if (s.at(0) == s.at(1) && s.at(0) == s.at(2) && s.at(1) == s.at(2)) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
