#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;

int main() {
  int X; cin>>X;
  bool ans = X==3 || X==5 || X==7;
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}

