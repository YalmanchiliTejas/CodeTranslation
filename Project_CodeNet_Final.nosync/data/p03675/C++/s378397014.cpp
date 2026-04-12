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
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

deque<ll> data;
ll n;

/* add your algorithm here */

int main() {
  cin >> n;
  ll a;
  if (n % 2) {
    for (int i = 0; i < n; ++i) {
      cin >> a;
      if (i % 2 == 1) {
        data.push_back(a);
      } else {
        data.push_front(a);
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      cin >> a;
      if (i % 2 == 0) {
        data.push_back(a);
      } else {
        data.push_front(a);
      }
    }
  }

  for (auto itr : data) {
    cout << itr << " ";
  }

  cout << endl;
}
