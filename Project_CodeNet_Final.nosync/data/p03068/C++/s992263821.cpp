// clang++ -std=c++14 -stdlib=libc++ -O2 ./*.cpp

#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
// #include <bits/stdc++.h>
using namespace std;

#define size_t int
typedef long long ll;
// #define int long long
typedef vector<int> VI;
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define debug(x) cerr << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl;
#define debug1(i, x) cerr << "(" << (i) <<  ") " << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl;
#define debug2(i, j, x) cerr << "(" << (i) << ", " << (j) <<  ") " << #x << " = " << (x) << " (line " << __LINE__ << ")" << endl;
template <typename T> class vec2d : public vector<vector<T>> {
public:
    vec2d(int H, int W): vector<vector<T>> (H, vector<T>(W)) {
    }
};
template <typename T> istream& operator >> (istream& is, vector<T>& vec){
  for(T& x: vec) is >> x;
  //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいいです。
  return is;
}
template <typename T> ostream& operator << (ostream& os, vector<T>& vec){
  REP(i, vec.size()) {
    os << vec[i] << ( i+1 == vec.size() ? "" : " " );
  }
  return os;
}
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0);
        // cout<<fixed<<setprecision(20);
    };
}aaaaaaa;

signed main(signed argc, char **argv) {
  int N;
  cin >> N;
  char S[N + 1];
  int K;
  cin >> S >> K;
  char x = S[K - 1];
  for (size_t i = 0; i < N; i++) {
    if (S[i] != x) {
      S[i] = '*';
    }
  }
  cout << S << endl;
  return 0;
}
