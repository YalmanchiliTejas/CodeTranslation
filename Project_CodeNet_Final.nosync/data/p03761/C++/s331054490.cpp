#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;
  vector<string> S(N);
  vector<map<char, ll>> ms(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    for (int j = 0; j < S[i].length(); j++) {
      ms[i][S[i][j]]++;
    }
  }
  string ans = "";
  for (char c = 'a'; c <= 'z'; c++) {
    ll shared_num = 100;
    for (int i = 0; i < N; i++) {
      shared_num = min(shared_num, ms[i][c]);
    }
    ans += string(shared_num, c);
  }
  cout << ans << endl;
  return 0;
}