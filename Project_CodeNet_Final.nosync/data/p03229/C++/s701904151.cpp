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
  int N; cin >> N;
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  ll ans1 = 0;
  ll now1 = A[0], now2 = A[0];
  int index_L = 1, index_R = N - 1;
  while (index_L <= index_R){
    vector <Pli> now(4);
    now[0] = make_pair(abs(now1 - A[index_L]), 0);
    now[1] = make_pair(abs(now1 - A[index_R]), 1);
    now[2] = make_pair(abs(now2 - A[index_L]), 2);
    now[3] = make_pair(abs(now2 - A[index_R]), 3);
    sort(now.begin(), now.end(), greater<Pli>());

    ans1 += now[0].first;
    int num = now[0].second;
    if (num == 0){
      now1 = A[index_L]; index_L++;
    }else if (num == 1){
      now1 = A[index_R]; index_R--;
    }else if(num == 2){
      now2 = A[index_L]; index_L++;
    }else{
      now2 = A[index_R]; index_R--;
    }
  }

  cout << ans1 << endl;

  return 0;
}
