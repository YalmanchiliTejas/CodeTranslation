#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> count(26, 100);
  for (auto i = 0; i < N; i++) {
    string s;
    cin >> s;
    vector<ll> tmp(26, 0);
    for (char c : s) tmp[c-'a']++;
    for (auto i = 0; i < count.size(); i++) {
//      cout << "count[" << i << "]=" << count[i] << " tmp=" << tmp[i] << endl;
      count[i] = min(count[i], tmp[i]);
    }
  }
  string res = "";
  for (auto i = 0; i < count.size(); i++) {
    for (auto j = 0; j < count[i]; j++) {
      res += (char)('a' + i);
    }
  }

  cout << res << endl;

  return 0;
}
