/*
 * A.cpp
 *
 *  Created on: 2017/06/18
 *      Author: jin
 */

#define MYDEBUG
#include <bits/stdc++.h>

#ifdef MYDEBUG
#define dbp(x) cout<<#x<<": "<<x<<endl
#define dbp2(x,y) cout<<#x<<","<<#y<<": "<<x<<","<<y<<endl
#define dbp3(x,y,z) cout<<#x<<","<<#y<<","<<#z<<": "<<x<<","<<y<<","<<z<<endl
#define dbp4(w,x,y,z) cout<<#w<<","<<#x<<","<<#y<<","<<#z<<": "<<w<<","<<x<<","<<y<<","<<z<<endl
#define ifcin(x) std::ifstream cin(x)
#else
#define dbp(x)
#define dbp2(x,y)
#define dbp3(x,y,z)
#define dbp4(w,x,y,z)
#define ifcin(x)
#endif
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for(int i=from; i<to; ++i)
#define REP(i, from, to) for(int i=from; i<=to; ++i)
#define EPS = 1e-14;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::swap;
using std::string;
using std::fill;
using std::pair;
using std::sort;
using std::reverse;
using std::pair;
using std::greater;
using std::priority_queue;
using std::ostream;
typedef std::complex<int> P;

template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i] << endl;
  }
  return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last) {
      out << ",";
    }
  }
  out << "]";
  return out;
}

using std::deque;
const int MAX_N = 2 * 100010;
int n;
deque<int> v;
deque<int> b;

void solve() {
  cin >> n;
//  rep(i,0,n)
//  {
//    int a;
//    cin >> a;
//    v.push_back(a);
//    reverse(all(v));
//  }
  int even = (n % 2 == 0 ? 1 : 0);
  rep(i,0,n)
  {
    int a;
    cin >> a;
//    v.push_back(a);
//    reverse(all(v));
    if ((i + even) % 2 != 0) {
      b.push_back(a);
    } else {
      b.push_front(a);
    }
  }

//  rep(i,0,n-1)
//  {
//    cout << v[i] << " ";
//  }
//  cout << v[n - 1] << endl;
  rep(i,0,n-1)
  {
    cout << b[i] << " ";
  }
  cout << b[n - 1] << endl;
}

int main() {
  solve();
}

