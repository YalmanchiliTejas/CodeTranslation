#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <utility>
#include <cctype>
#include <iterator>
////////////////////////////////////////////////
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define FOR(i, m, n) for (int i = (int)m; i < (int)n; i++)
#define REPvec(itr, mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)
#define REPe(e, mp) for (auto& e : mp)
#define all(x) x.begin(), x.end()
#define MOD 1000000007  // 1e9+7
using namespace std;
using ll = long long int;
using vecint = vector<int>;
using vecll = vector<ll>;
using vec2int = vector<vector<int>>;
using P = pair<int, int>;
////////////////////////////////////////////////
////////////////////////////////////////////////
int main() {
  ////////////////////////////////////////////////
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ////////////////////////////////////////////////
  int a;
  cin >> a;
  if(a >= 30){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
}
