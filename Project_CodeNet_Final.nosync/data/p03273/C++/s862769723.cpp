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


int main(){
  int h, w;
  char s[150][150];
  bool r[150] = {}, c[150] = {};

  scanf("%d%d", &h, &w);

  for(int i=0;i<h;i++){
    scanf("%s", s[i]);
    for(int j=0;j<w;j++){
      r[j] |= s[i][j] == '#';
      c[i] |= s[i][j] == '#';
    }
  }

  for(int i=0;i<h;i++){
    if(!c[i]) continue;
    for(int j=0;j<w;j++){
      if(!r[j]) continue;
      printf("%c", s[i][j]);
    }
    puts("");
  }

  return 0;
}
