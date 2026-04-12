#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define sz(c) int((c).size())

typedef pair<int, int> pii;
priority_queue<pii> q;


int main(int argc, char **argv)
{
  int team, ac;
  char c;
  for (;;) {
    cin >> team >> c >> ac;
    if (!team && !ac)
      break;
    q.push(pii(ac, team));
  }
  map<int, int> m;
  int rank = 0, prev_score = 0;
  while (sz(q)) {
    pii p = q.top(); q.pop();
    if (p.first != prev_score) {
      prev_score = p.first;
      ++rank;
    }
    m[p.second] = rank;
  }
  while (cin >> team) {
    cout << m[team] << endl;
  }
  return 0;
}