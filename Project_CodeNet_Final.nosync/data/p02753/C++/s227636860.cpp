/**
	Language: C++ 11
	Author  : ebby21
**/

#include <bits/stdc++.h>

using namespace std;

#define FASTIO() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define DEBUG(var) cerr << '\n' << #var << "\t:\t" << var << '\n'
#define FORF(i, L, U) for (ll i = (L); i <= (U); ++i)
#define FORR(i, U, L) for (ll i = (U); i >= (L); --i)
#define FORE(i, x) for (auto i = (x).begin(); i != (x).end(); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< ii > vii;

int main() {
	FASTIO();
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (char c : s) {
    if (c == 'A')++a;
    else ++b;
  }
  if (a == 0 || b == 0) cout << "No\n";
  else cout << "Yes\n";
	return 0;
}
