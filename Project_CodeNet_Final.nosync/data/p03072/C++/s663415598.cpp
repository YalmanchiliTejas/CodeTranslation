//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
const ll nmax = 1e9 + 7;
const ll mod = 998244353;
const double PI = 2 * asin(1);

int main(){
  int N; cin >> N;
  vector <int> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];

  int ans = 0, now = 0;
  for (int i = 0; i < N; i++){
    if (now <= H[i]){
      ans++; now = H[i];
    }
  }
  cout << ans << endl;
  return 0;
}
