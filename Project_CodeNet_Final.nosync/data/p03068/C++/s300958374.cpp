#include<iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
 
int main() {
  int n, k;
  string s, targ;
  cin >> n;
  cin >> s;
  cin >> k;
  targ = s[k - 1];
  for (int i = 0; i < n; i++){
    if (s[i] != targ[0]) s[i] = '*';
  }
  cout << s << endl;
}