#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;

int solve(){
  string s; cin >> s;
  int a = count(s.begin(), s.end(), 'A');
  cout << (a && 3-a ? "Yes" : "No") << endl;
}

int main(){
  solve();
  return 0;
}
