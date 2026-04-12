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

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

ll AN(ll A, ll N){
  if (N == 0){
    return 1;
  }else{
    if (N % 2 == 0){
      return AN(A * A % nmax, N / 2) % nmax;
    }else{
      return A * AN(A * A % nmax, N / 2) % nmax;
    }
  }
}

ll nCk(ll N, ll K){
  ll ans = 1;
  for (ll i = 0; i < K; i++){
    ans *= N - i; ans %= nmax;
    ans *= AN(i + 1, nmax - 2); ans %= nmax;
  }
  return ans;
}

int main(){
  ll N, M, K; cin >> N >> M >> K;

  ll num = nCk(N * M - 2, K - 2);

  vector <ll> dx(N), dy(M);
  for (ll i = 1; i < N; i++){
    dx[i] = M * M * (N - i) * i % nmax;
    dx[i] += dx[i - 1]; dx[i] %= nmax;
  }

  for (ll i = 1; i < M; i++){
    dy[i] = N * N * (M - i) * i % nmax;
    dy[i] += dy[i - 1]; dy[i] %= nmax;
  }
  ll ans = dx[N - 1] + dy[M - 1]; ans %= nmax;
  ans *= num; ans %= nmax;
  cout << ans << endl;

  return 0;
}