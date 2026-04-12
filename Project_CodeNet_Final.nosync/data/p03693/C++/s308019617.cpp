#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);

void solve() {
  int r,g,b; cin >> r >> g >> b;
  // string ans = to_string(r+g+b);
  string r_str= to_string(r);
  string g_str= to_string(g);
  string b_str= to_string(b);
  string ans = r_str + g_str + b_str;
  int num = stoi(ans);
  if (num%4==0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }

}

int main() {
  solve();
  return 0;
}
