#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;
#define PI 3.14159265359;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n;
  cin >> n;
  int moji[26];
  for (char c = 'a'; c <= 'z'; c++) {
    moji[c - 'a'] = INF;
  }
  rep (i, n) {
    string tmp;
    cin >> tmp;

    int moji2[26];
    for (char c = 'a'; c <= 'z'; c++) {
      moji2[c - 'a'] = 0;
    }

    rep (j, tmp.size()) {
      moji2[tmp[j] - 'a']++;
    }

    for (char c = 'a'; c <= 'z'; c++) {
      moji[c - 'a'] = min(moji[c - 'a'], moji2[c - 'a']);
    }
  }

  // for (char c = 'a'; c <= 'z'; c++) {
  //   P(moji[c - 'a']);
  // }

  string ans = "";
  for (char c = 'a'; c <= 'z'; c++) {
    string tmp{c};
    rep (i, moji[c - 'a']) ans += tmp;
  }
  P(ans);

  return 0;
}