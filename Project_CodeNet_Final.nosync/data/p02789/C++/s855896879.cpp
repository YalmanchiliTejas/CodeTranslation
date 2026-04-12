#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define printYesNo(condition) cout << (condition ? "Yes" : "No") << endl

int solve(){
  int n, m; cin >> n >> m;
  printYesNo(n==m);
  return 0;
}

int main(){
  solve();
  return 0;
}
