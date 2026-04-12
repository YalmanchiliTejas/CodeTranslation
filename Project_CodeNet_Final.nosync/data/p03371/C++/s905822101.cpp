//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1ll << 60;
const double PI = 2 * asin(1);

ll A, B, C, X, Y, ans = INF;
int main(){
  cin >> A >> B >> C >> X >> Y;

  for (ll i = 0; i <= 2 * max(X, Y); i+=2){
    ll now = C * i;
    now += A * max(X - i / 2, 0ll) + B * max(Y - i / 2, 0ll);
    ans = min(ans, now);
  }
  cout << ans << endl;

  return 0;
}
