#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <chrono>
#include <ctime>
#include <bitset>
#include <iterator>
#include <cmath>
#include <stack>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<long long, long long>
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  rep(i, s.size()-1) {
    if (s[i] == 'A' && s[i+1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}
