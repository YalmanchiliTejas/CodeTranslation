#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long
#define INF 100000000
#define mod 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll int, ll int>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

template<class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int N;
int a[110000];

int main () {
  cin >> N;
  Rep(i, N) cin >> a[i];

  multiset<int> st;
  st.insert(a[0]);

  for(int i=1;i<N;++i) {
    auto itr = st.lower_bound(a[i]);

    if (itr == st.begin()) {
      st.insert(a[i]);
    } else {
      itr--;
      st.erase(itr);
      st.insert(a[i]);
    }
  }

  cout << st.size() << "\n";
}