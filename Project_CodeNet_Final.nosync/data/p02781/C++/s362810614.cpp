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
  if (k == 1) {
    ll ans = s[0] - '0';
    ans += 9 * (m - 1);
    cout << ans << endl;
  }
  else if (k == 2) {
    ll cnt = 0, memo = -1;
    if (m < 2) {
      cout << 0 << endl;
      return 0;
    }
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
    if (m < 3) {
      cout << 0 << endl;
      return 0;
    }
    ll cnt = 0, memo1 = -1, memo2 = -1;
    for (ll i = 0; i < m; i++) {
      if (s[i] != '0') {
        cnt++;
        if (cnt == 2) memo1 = i;
        if (cnt == 3) {
          memo2 = i;
          break;
        }
      }
    }
    ll a, b, c;
    if (memo1 == -1) {
      if (s[0] == '1') {
        a = 9;
        b = 9;
        c = 9;
        m--;
        memo1 = 1;
        memo2 = 2;
      }
      else {
        a = s[0] - '0' - 1;
        b = 9;
        c = 9;
        memo1 = 1;
        memo2 = 2;
      }
    }
    else if (memo2 == -1) {
      if (s[memo1] == '1') {
        if (memo1 == m - 1 || memo1 == m - 2) {
          if (s[0] == '1') {
            a = 9;
            b = 9;
            c = 9;
            m--;
            memo1 = 1;
            memo2 = 2;
          }
          else {
            a = s[0] - '0' - 1;
            b = 9;
            c = 9;
            memo1 = 1;
            memo2 = 2;
          }
        }
        else {
          a = s[0] - '0';
          b = 9;
          c = 9;
          memo1++;
          memo2 = memo1 + 1;
        }
      }
      else {
        if (memo1 == m - 1) {
          if (s[0] == '1') {
            a = 9;
            b = 9;
            c = 9;
            m--;
            memo1 = 1;
            memo2 = 2;
          }
          else {
            a = s[0] - '0' - 1;
            b = 9;
            c = 9;
            memo1 = 1;
            memo2 = 2;
          }
        }
        else {
          a = s[0] - '0';
          b = s[memo1] - '0' - 1;
          c = 9;
          memo2 = memo1 + 1;
        }
      }
    }
    else {
      a = s[0] - '0';
      b = s[memo1] - '0';
      c = s[memo2] - '0';
    }
    ll ans = 243 * (m - 3) * (m - 2) / 2 * (m - 1);
    ans += (m - memo1) * (m - memo2) / 2 * 81 * (a - 1);
    ans += (m - memo1 - 1) * (m - memo1 - 2) / 2 * 81;
    ans += 9 * (b - 1) * (m - memo2);
    ans += 9 * (m - memo2 - 1);
    ans += c;
    cout << ans << endl;
  }
}