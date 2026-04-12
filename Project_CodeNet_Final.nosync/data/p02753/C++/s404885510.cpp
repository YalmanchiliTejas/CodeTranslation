#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define ALL(x) (x).begin(), (x).end()     //昇順
#define RALL(x) (x).rbegin(), (x).rend()  // 降順
#define FOR(i, c) \
  \ for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
const long long mod = 1e9 + 7;
typedef long long ll;  // ll とdoubleは違う
typedef priority_queue<int> PQ;
typedef vector<long long> VL;
typedef vector<bool> VB;
typedef vector<int> VI;  // VI a(n);
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<VS> VSS;
typedef vector<VC> VCC;
typedef vector<VI> VII;  // VII a(n,vector<int>(m)) n * m
typedef vector<VL> VLL;
typedef vector<VB> VBB;
typedef pair<int, int> PII;
typedef map<int, int> MP;  // MP a;
typedef vector<pair<ll, ll>> PS;

template <class T, class U>  // chmax(max, a);
bool chmax(T &a, U b) {
  if (a <= b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class U>  // chmin(min,a)
bool chmin(T &a, U b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>  // operator << (cout,a);
ostream &operator<<(ostream &os, vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) { os << v[i] << (i < v.size() - 1 ? ", " : ""); }
  os << "}";
  return os;
}

// g++ -std=c++11 prac.cpp

int main() {
  ll x=0,y=0,k,n,m,h,w,ans=0,sum=0,Max=1,Min=1e9+1;
  string s,t;
  bool ok = false;
  cin >> s;
  char c = s[0];
  rep(i,3){
    if(c == s[i]){
      ans++;
    }
  }
  if(ans == 3)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}