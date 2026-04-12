#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

int N, s[SIZE];
map<int,ll> suml[SIZE], sumr[SIZE];

int main(){

  scanf("%d", &N);

  for (int i=0; i<N; i++) {
    scanf("%d", s+i);
  }

  for (int i=1; i<=N-1; i++) {
    ll sum = 0;
    for (int j=0; j<=N-1; j+=i) {
      sum += s[j];
      suml[j][i] = sum;
    }
  }

  for (int i=1; i<=N-1; i++) {
    ll sum = 0;
    for (int j=N-1; j>=0; j-=i) {
      sum += s[j];
      sumr[j][i] = sum;
    }
  }

  ll ans = 0;

  for (int A=1; A<N-1; A++) {
    int r = N-1 - A;
    for (int d=1; d*d<=r; d++) {
      if (r % d) continue;

      {
        int B = A - d;
        if (B > 0 && (A % d != 0 || A / d > r / d)) {
          ans = max(ans, sumr[A][d] + suml[r][d]);
        }
      }
      {
        int B = A - r/d;
        if (B > 0 && (A % (r/d) != 0 || A / (r/d) > r / (r/d))) {
          ans = max(ans, sumr[A][r/d] + suml[r][r/d]);
        }
      }
    }
  }


  cout << ans << endl;

  return 0;
}
