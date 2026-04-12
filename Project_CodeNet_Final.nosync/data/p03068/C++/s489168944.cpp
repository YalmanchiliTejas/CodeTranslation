/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

// input/output
#include <iostream>
#include <fstream>
#include <sstream>
// container class
#include <array>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// math, algorithm
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
// etc
#include <bitset>
#include <cctype>
#include <cstring>
#include <chrono>
#include <iomanip>
#include <random>
#include <utility>
// using-directive
using namespace std;
// alias template
using int64 = int64_t;
using pii = pair<int, int>;
using pll = pair<int64_t, int64_t>;
// text macro replacement
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define print(x) cout << (x) << '\n'
#define debug(x) cout << #x << ": " << (x) << '\n'

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  string s; cin >> s;
  int k; cin >> k;

  --k;
  char c = s[k];

  for (int i = 0; i < (int) s.size(); ++i){
    if (s[i] != c) cout << '*';
    else cout << s[i];
  }
  cout << endl;


  return 0;
}