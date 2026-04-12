#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  ll n, x, m;

  cin >> n >> x >> m;

  ll ans = 0;

  ll cycle = 0, tot = 0, left = n;

  vector<char> u(m + 1);

  while(true) {
    ans += x;
    left--;
    if(left == 0) { cout << ans; return 0; }
    if(u[x]) break;
    u[x] = true;
    x = (x * x) % m;
  }

  ll stop = x;

  do {
    tot += x;
    cycle++;
    x = (x * x) % m;
  } while(x != stop);

  ans += tot * (left / cycle);

  left %= cycle;

  while(left--) {
    x = (x * x) % m;
    ans += x;
  }

  cout << ans;

  return 0;
}
/*

*/
