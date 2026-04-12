#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define P pair<int, int>
#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define LAST(x) (x)[(x).size() - 1]
#define GI(name) \
  int(name);     \
  scanf("%d", &(name))
#define GI2(name1, name2) \
  int(name1), (name2);    \
  scanf("%d %d", &(name1), &(name2))
#define GI3(name1, name2, name3) \
  int(name1), (name2), (name3);  \
  scanf("%d %d %d", &(name1), &(name2), &(name3))
#define GVI(name, size)    \
  vector<int>(name)(size); \
  FOR(i, (size)) scanf("%d", &(name)[i])
#define GS(name) \
  string(name);  \
  cin >> (name);
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

string to_string(string s) {
  return s;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  FOR(i, v.size() - 1) { ret += to_string(v[i]) + ","; }
  if (v.size() > 0) {
    ret += to_string(LAST(v));
  }
  ret += "}";
  return ret;
}

void debug() {
  cerr << endl;
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

int main() {
  GI2(N, M);
  vector<vector<int>> G(N);
  FOR(i, M) {
    GI2(a, b);
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }
  stack<pair<int, unordered_set<int>>> s;
  s.push(pair<int, unordered_set<int>>(0, unordered_set<int>()));
  int ans = 0;
  while (!s.empty()) {
    pair<int, unordered_set<int>> p = s.top();
    s.pop();
    p.second.insert(p.first);
    if (p.second.size() == N) {
      ans++;
      continue;
    }
    for (int v : G[p.first]) {
      if (!p.second.count(v)) {
        unordered_set<int> u = p.second;
        s.push(pair<int, unordered_set<int>>(v, u));
      }
    }
  }
  print(ans);
  return 0;
}