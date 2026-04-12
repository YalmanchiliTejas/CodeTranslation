#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, j, k) for (int i = j; i < k; i++)
#define REP(i, j) FOR(i, 0, j)
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int main() {

  int X;
  cin >> X;

  if (X == 3 or X == 5 or X == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
