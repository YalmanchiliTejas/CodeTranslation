//q1 abc064
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
#define pb push_back
#define mkt make_tuple
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

  int r, g, b;
  string ans;
  cin >> r >> g >> b;
  if ((r*100+g*10+b) % 4 == 0) {
    ans = "YES";
  } else {
    ans = "NO";
  }

  cout << ans << endl;
  return 0;
}
