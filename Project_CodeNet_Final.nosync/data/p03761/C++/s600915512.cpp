#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n;
  cin >> n;
  vector<string> s(n);
  for (ll i = 0; i < n; i++) cin >> s[i];

  map<char, ll> ans;
  for (ll i = 0; i < s[0].size(); i++) {
    ans[s[0][i]]++;
  }
  
  for (ll i = 1; i < n; i++) {
    map<char, ll> m;
    for (ll j = 0; j < s[i].size(); j++) {
      m[s[i][j]]++;
    }
    for (char c = 'a'; c <= 'z'; c++) {
      ans[c] = min(ans[c], m[c]);
    }
  }
  for (auto i = ans.begin(); i != ans.end(); i++) {
    for (ll j = 0; j < (i -> second); j++) {
      cout << (i -> first);
    }
  }
  cout << endl;
}
