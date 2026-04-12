#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <map>
#define REP(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;

string s;
ll q, a, f;
char c;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> s;
  if (s == "AAA" || s == "BBB") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}

