#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <fstream>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  int x[n];
  int y[n];
  rep(i,n) {
    cin>>x[i];
    y[i] = x[i];
  }
  sort(y, y + n);
  map<int, int> mp;
  rep(i,n) {
    if(n / 2 > i) {
      mp[y[i]] = y[n/2];
    } else {
      mp[y[i]] = y[n/2 - 1];
    }
  }
  rep(i,n) {
    cout << mp[x[i]] << endl;
  }

  return 0;
}
