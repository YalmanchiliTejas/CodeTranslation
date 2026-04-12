#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repf(i,a,b) for (int i = (a); i < (b); i++)
#define repi(i,a,b) for (int i = (a); i <= (b); i++)
#define repr(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x)  cout << #x << " = " << (x) << endl;
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using tiii = tuple<int, int, int>;

int main() {
  int X, Y, Z; cin >> X >> Y >> Z;
  cout << (X-Z)/(Y+Z) << endl;
}