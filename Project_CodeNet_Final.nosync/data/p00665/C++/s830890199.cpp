#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef long long lli;

int N, M, K, L;
vector<pair<int, string> > V;
map<string, int> m;
vector<int> H;


int needCost(pair<int, string> &a, pair<int, string> &b) {
  if(a <= b) return 0;
  return a.first - b.first + ((a.second > b.second) ? 1 : 0);
}

bool isTrue(int a) {
  int line = K-a;
  lli cost = 0;
  for(int i = 0; i < a; ++i) {
    cost += needCost(V[H[i]], V[line]);
    if(H[i] <= line) ++line;
  }
  return cost <= L;
}

int solve() {
  int l, r, ans;
  l = 0; r = min(M+1, K+1); ans = 0;
  while(l < r) {
    int a = (l+r)/2;
    if(isTrue(a)) {
      ans = a;
      l = a+1;
    } else {
      r = a;
    }
  }
  return ans;
}

int main() {
  while(cin >> N >> M >> K >> L && (N || M || K || L)) {
    V.clear();
    m.clear();
    H.clear();
    for(int i = 0; i < N; ++i) {
      pair<int, string> p;
      cin >> p.second >> p.first;
      p.first *= -1;
      V.push_back(p);
    }
    sort(V.begin(), V.end());

    for(int i = 0; i < V.size(); ++i) {
      m[V[i].second] = i;
    }

    for(int i = 0; i < M; ++i) {
      string name;
      cin >> name;
      H.push_back(m[name]);
    }
    sort(H.begin(), H.end());
    cout << solve() << endl;
  }
  return 0;
}