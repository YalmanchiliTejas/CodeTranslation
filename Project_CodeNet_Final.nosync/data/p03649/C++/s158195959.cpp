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

const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

int main(){
  ll N; cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = 0;
  while (true){
    ll sum = 0;
    vector <ll> now(N);
    for (int i = 0; i < N; i++){
      now[i] = A[i] / N;
      sum += now[i];
    }
    if (sum == 0) break;

    ans += sum;
    for (int i = 0; i < N; i++){
      A[i] = A[i] - now[i] * N + (sum - now[i]);
    }
  }
  cout << ans << endl;

  return 0;
}
