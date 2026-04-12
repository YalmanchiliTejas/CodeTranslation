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

int main() {
  ll x, y, z;
  cin >> x >> y >> z;
  ll ans = 0;
  while (x > y + z) {
    x -= y + z;
    ans++;
  }
  if (x < z) ans--;
  cout << ans << endl;
}