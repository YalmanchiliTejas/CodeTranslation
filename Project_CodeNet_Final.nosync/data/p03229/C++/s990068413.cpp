#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n; cin >> n;
  vector<ll> a(n,0);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

  deque<ll> deq;
  sorti(a);
  deq.push_front(a[0]);

  ll i = 1, j = n-1, judge = 0;
  while (true) {
    if (i <= j) deq.push_front(a[j--]); else break;
    if (i <= j) deq.push_back(a[j--]); else break;
    if (i <= j) deq.push_front(a[i++]); else break;
    if (i <= j) deq.push_back(a[i++]); else break;
  }

  ll res = 0;
  for (int i = 0; i < deq.size()-1; ++i) {
    res += abs(deq[i] - deq[i+1]);
  }

  ll tmp = deq.back(); deq.pop_back();
  deq.push_front(tmp);

  ll rest = 0;
  for (int i = 0; i < deq.size()-1; ++i) rest += abs(deq[i] - deq[i+1]);

  cout << max(res,rest) << endl;
}
