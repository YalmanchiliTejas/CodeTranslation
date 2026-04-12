#include <bits/stdc++.h>
using namespace std;
int main () {
  char a;
  map<char, int> mp;
  for(int i = 0; i < 3; i++){
    cin >> a;
    mp[a]++;
  }
  if(mp.size() == 2)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}