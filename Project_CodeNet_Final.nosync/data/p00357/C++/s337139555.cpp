#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1LL<<60;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------
int main(){
  int N;
  cin >> N;
  vector<int> d(N);
  for(int i=0; i<N; i++){
    cin >> d[i];
  }
  bool can = true;
  int m = 0;
  for(int i=0; i<N; i++){
    if(m < i){
      can = false;
    }
    if(d[i] < 10){
      if(m < i){
        can = false;
      }
    }else{
      chmax(m,i+d[i]/10);
    }
  }
  m = N-1;
  for(int i=N-1; i>=0; i--){
    if(i < m){
      can = false;
    }
    if(d[i] < 10){
      if(m > i){
        can = false;
      }
    }else{
      chmin(m,i-d[i]/10);
    }
  }
  if(can){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return 0;
}

