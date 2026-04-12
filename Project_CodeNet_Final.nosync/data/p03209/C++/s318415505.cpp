#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

ll ans;
vector<ll> patti(51);
vector<ll> total(51);

void solve(ll N, ll x){
  if(N == 1) {
    if(x >= 5){
      ans += 3;
    } else {
      ans = ans + x - 1;
    }
    
    return;
  }
  if(total[N]/2 + 1 <= x) { // 半分以上はいる場合
    x = x - total[N]/2 - 1;
    ans += patti[N-1] + 1;
  }
  else {
    x--; // 1番目のバンズを外す
  }
  if(x <= 0) return;
  solve(N-1, x);
}

int main() {
  ll N, x;
  cin >> N >> x;
  
  patti[0] = 1;
  total[0] = 1;
  for(int i = 1; i <= 50; i++){
    patti[i] = 1 + patti[i-1]*2;
    total[i] = 3 + total[i-1]*2;
  }

  ans = 0;
  solve(N, x);
  
  print(ans);
}
