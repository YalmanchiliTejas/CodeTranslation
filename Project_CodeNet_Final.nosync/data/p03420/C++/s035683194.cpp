#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  ll res = 0;
  if(k == 0){
    cout << n * n << endl;
    return 0;
  }

  for (ll b = k+1; b <= n; b++) {
    ll num = n / b;
    num *= b - k;
    res += num;
    ll tmp = n % b;
    // cout << tmp << endl;
    res += max(tmp - k + 1, 0ll);
    // cout << res << endl;
  }
  cout << res << endl;
}
