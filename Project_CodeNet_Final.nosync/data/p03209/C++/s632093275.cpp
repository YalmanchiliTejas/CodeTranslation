#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i, s, n) for(int i=s; i<n; i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;


vector<ll> p_num;
vector<ll> b_num;
vector<ll> s_num;

ll patty(ll n, ll k) {
  if(n==0) return 1; // レベル0バーガーは pattyのみ
  if(k<=1) {
    return 0; // 端はBread
  } else if(k<= 1 + s_num[n-1]){
    return patty(n-1, k-1) + 0;
  } else if(k== 2 + s_num[n-1]) {
    return p_num[n-1] + 1;
  } else if(k<= 2 + s_num[n-1]*2) {
    return patty(n-1, k-2-s_num[n-1]) + p_num[n-1] + 1;
  } else { //if(k==s_num[n]) {
    return p_num[n];
  }
}

int main() {
  int N;
  ll K;
  cin >> N >> K;

  p_num.resize(N+1); // p_num[i].. レベルiバーガーのPの数
  b_num.resize(N+1); // Bの数
  s_num.resize(N+1);
  p_num[0] = 1;
  b_num[0] = 0;
  s_num[0] = 1;
  
  rep2(i, 1, N+1) {
    p_num[i] = 1 + p_num[i-1]*2;
    b_num[i] = 2 + b_num[i-1]*2;
    s_num[i] = p_num[i] + b_num[i];
  }
  //rep(i, K+1) cout << patty(N, i) << endl;


  cout << patty(N, K) << endl;
  
  return 0;
}
