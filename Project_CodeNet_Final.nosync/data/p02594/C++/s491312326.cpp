#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <functional>

using namespace std;

#define A first
#define B second

typedef long long ll;
constexpr int MOD = 1000000007;

void solve() {
  int X;
  cin >> X;
  if(X >= 30){
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  T = 1;
  //cin >> T;
  while(T--){
    solve();
  }
}