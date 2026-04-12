#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
ll llmax = LLONG_MAX;
string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
vi d1 = {1, 0, -1, 0}, d2 = {0, 1, 0, -1};
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}
void sorti(vi &a) {sort(a.begin(), a.end());}
void sortll(vll &a) {sort(a.begin(), a.end());}
void sorts(vs &a) {sort(a.begin(), a.end());}

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll m = s.size();
  if (m < k) {
    cout << 0 << endl;
    return 0;
  }
  if (k == 1) {
    ll ans = s[0] - '0';
    ans += 9 * (m - 1);
    cout << ans << endl;
  }
  else if (k == 2) {
    ll cnt = 0, memo = -1;
    for (ll i = 0; i < m; i++) {
      if (s[i] != '0') {
        cnt++;
        if (cnt == 2) {
          memo = i;
          break;
        }
      }
    }
    ll a, b;
    if (memo == -1) {
      if (s[0] == '1') {
        a = 9;
        b = 9;
        m--;
        memo = 1;
      }
      else {
        a = s[0] - '0' - 1;
        b = 9;
        memo = 1;
      }
    }
    else {
      a = s[0] - '0';
      b = s[memo] - '0';
    }
    ll ans = (m - 1) * (m - 2) / 2 * 81;
    ans += 9 * (m - 1) * (a - 1);
    ans += 9 * (m - memo - 1);
    ans += b;
    cout << ans << endl;
  }
  else {
    string ss;
    for (ll i = 0; i < m; i++) ss.push_back('0');
    ll ans = 243 * (m - 3) * (m - 2) / 2 * (m - 1);
    for (ll a = 1; a <= s[0] - '0'; a++) {
      for (ll b = 1; b < 10; b++) {
        for (ll c = 1; c < 10; c++) {
          for (ll y = 1; y < m - 1; y++) {
            for (ll z = y + 1; z < m; z++) {
              string sss = ss;
              sss[0] = a + '0';
              sss[y] = b + '0';
              sss[z] = c + '0';
              if (sss <= s) {
                ans++;
              }
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}