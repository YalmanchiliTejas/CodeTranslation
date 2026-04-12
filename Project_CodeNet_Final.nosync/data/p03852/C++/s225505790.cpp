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

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<long long, long long>
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  char c; cin >> c;
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }

}