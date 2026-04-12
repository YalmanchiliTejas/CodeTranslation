#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf  = 1e6+5;
vector<int> freq (5);
int main() {
  string s; cin >> s;
  set<char> ss;
  for (char i : s){
      ss.insert(i);
  }
  if (ss.size() > 1){
      cout << "Yes";
  }
  else{
      cout << "No";
  }
}