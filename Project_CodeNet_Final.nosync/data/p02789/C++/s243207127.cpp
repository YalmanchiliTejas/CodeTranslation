#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < (int) b; i++)
#define F0R(i, a) FOR (i, 0, a)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define R0F(i, a) for (int i = a; i >= 0; i--)
#define GO(i, a) for (auto i : a)

#define f first
#define s second
#define eb emplace_back
#define pb push_back
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;
typedef long long i64;
typedef vector<i64> vi64;
typedef pair<i64, i64> pi64;
typedef vector<pi64> vpi64;
typedef vector<vi64> vvi64;
typedef vector<vpi64> vvpi64;

const int dr[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dc[] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int ms[] = {+31, +29, +31, +30, +31, +30, +31, +31, +30, +31, +30, +31};
const int rm[] = {+1, +4, +5, +9, +10, +40, +50, +90, +100, +400, +500, +900, +1000};

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << (a == b ? "Yes" : "No") << '\n';
  return 0;
}

