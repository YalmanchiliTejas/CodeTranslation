#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;

bool custom1 (pii a, pii b) {
  return (a.first < b.first);
}

bool custom2 (pii a, pii b) {
  return (a.second < b.second);
}

const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;

  if(n == m) cout << "Yes" << endl;
  else cout << "No" << endl;
}