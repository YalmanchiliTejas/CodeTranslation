// The very basic /////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define ALL_H 1

// Debug it by D(x) ///////////////////////////////////////////////////////////
#define DEBUG 0
#if DEBUG
#define D(x) x
#else
#define D(x)
#endif

// Print elements of containers using << operator /////////////////////////////
// pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
  return s << "(" << p.first << ", " << p.second << ")";}
// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  for (auto &elem : v) {
    s << elem;
    if (&elem != &v.back()) s << " ";
  }
  return s;
}
// 2 dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  for (auto &elem : vv) {
    s << elem;
    if (&elem != &vv.back()) s << endl;
  }
  return s;
}
// map
template<typename T1, typename T2> ostream& operator<<(ostream& s, const map<T1, T2>& m) {
  s << "{" << endl;
  for (auto &elem: m) {
    s << " " << elem.first << " : " << elem.second << endl;
  }
  s << "}";
  return s;
}
//set
template<typename T> ostream& operator<<(ostream& s, const set<T>& m) {
  s << "{ ";
  for (auto &elem: m) {
    s << elem << " ";
  }
  s << "}";
  return s;
}

// Convenient macros //////////////////////////////////////////////////////////

// types
#define ll long long
#define ld long double
#define int ll
#define Pi pair<int, int>
#define Graph vector<vector<int>>
#define WeightGraph vector<vector<Pi>>

// other
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))

// update max or min //////////////////////////////////////////////////////////

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// gcd
int gcd(int a,int b){return b?gcd(b,a%b):a;}

// for grids
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

///////////////////////////////////////////////////////////////////////////////
//                             Start Coding Here                             //
///////////////////////////////////////////////////////////////////////////////

signed main() {
  int x, y, z; cin >> x >> y >> z;
  int spp = y + z;
  D(cout << x << " "<< spp << endl);
  D(cout << x - z << endl);
  cout << (x-z) / spp << endl;
}
