#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
  	cin >> n;
  	ll mod = 1000000007;
  	vector<ll> a(n), suf(n);
  	for (int i = 0; i < n; i++)
    	cin >> a[i];
  	suf[n - 1] = a[n - 1];
  	for (int i = n - 2; i >= 0; i--) {
    	suf[i] = suf[i + 1] + a[i];
      	suf[i] %= mod;
    }
  	ll ans = 0;
  	for (int i = 1; i < n; i++) {
      	ans += a[i - 1] * suf[i];
      	ans %= mod;
    }
  	cout << ans;
    return 0;
}