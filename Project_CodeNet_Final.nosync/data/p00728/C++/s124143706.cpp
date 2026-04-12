#include <iostream>

#include <algorithm>
#include <numeric>

#include <vector>
#include <queue>
#include <stack>
#include <map>

#define FOR(i,b,e) for(int i=b;i<e;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

typedef pair<int, int> P;

const int MAX_N = 100;
int n;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    vector<int> scores;

    cin >> n; 
    if (n == 0) break;

    REP(i,n) {
      int s;
      cin >> s;
      scores.push_back(s);
    }

    sort(scores.begin(), scores.end());
    int sum = accumulate(scores.begin() + 1, scores.end() - 1, 0);

    cout << sum / (n - 2) << endl;
  }
}
