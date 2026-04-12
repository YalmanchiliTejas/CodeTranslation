#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <fstream>

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long unsigned int ll;

int main() {
  int n;
  cin >> n;
  int inf = 51;
  vector<int> countsAll(26, inf);
  for (int i = 0; i < n; ++i) {
    string S;
    cin >> S;
    vector<int> count(26, 0);
    for (int j = 0; j < (int)S.size(); ++j) {
      count[S[j] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      countsAll[i] = min(countsAll[i], count[i]);
    }
  }

  string ans = "";
  for (int i = 0; i < 26; ++i) {
    if (countsAll[i] == inf) continue;
    for (int j = 0; j < countsAll[i]; ++j) {
      ans += (char)(i + 'a');
    }
  }
  cout << ans << endl;

  return 0;
}
