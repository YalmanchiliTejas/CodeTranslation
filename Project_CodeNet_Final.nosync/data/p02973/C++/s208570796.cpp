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


int main() {
  int N, A[SIZE];
  multiset<int> ss;

  scanf("%d", &N);

  for (int i=0; i<N; i++) {
    scanf("%d", A+i);
  }

  for (int i=0; i<N; i++) {
    auto it = ss.upper_bound(A[i]-1);

    if (ss.begin() == it) {
      ss.insert(A[i]);
    } else {
      it--;
      ss.erase(it);
      ss.insert(A[i]);
    }
  }

  cout << ss.size() << endl;

  return 0;
}
