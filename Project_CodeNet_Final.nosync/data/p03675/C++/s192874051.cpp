//arc077 q1
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <deque>
#define pb push_back
#define pf push_front
#define mkt make_tuple
#define pqueue priority_queue
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
const int INF =  2147483647;
const ll INFLL = 9223372036854775807;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vi a;
  for (size_t i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    a.pb(ai);
  }

  deque<ll> b;
  for (size_t i = 0; i < n; i++) {
    if ((n-i) % 2 == 1) {
      b.pf(a[i]);
    } else {
      b.pb(a[i]);
    }
  }
  for_each(b.begin(), b.end(), [](ll x) {
    cout << x << ' ';
  });
  return 0;
}
