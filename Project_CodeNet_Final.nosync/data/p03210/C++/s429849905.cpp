#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

int main(){
  int X;
  cin >> X;
  if(X==3) cout << "YES" << endl;
  else if(X==5) cout << "YES" << endl;
  else if(X==7) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}