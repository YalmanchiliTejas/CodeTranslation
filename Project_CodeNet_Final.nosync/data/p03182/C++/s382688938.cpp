#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 2 * 105000;
const long long INF = 1e18L + 123;

struct node {
    long long mn;
    long long add;
};
node tree[4 * MAXN];

void add(int v, int L, int R, int l, int r, long long val) {
  if (l > r) 
    return;
  if (L == l && R == r) {
    tree[v].add += val;
  } else {
    int mid = L + (R - L) / 2;
    add(2 * v + 1, L, mid, l, min(mid, r), val);
    add(2 * v + 2, mid + 1, R, max(mid + 1, l), r, val);
    tree[v].mn = min(tree[2 * v + 1].mn + tree[2 * v + 1].add, tree[2 * v + 2].mn + tree[2 * v + 2].add);
  }
}

long long getMin(int v, int L, int R, int l, int r) {
    if (l > r) {
      return INF;
    }
    if (L == l && R == r) {
      return tree[v].mn + tree[v].add;
    }
    int mid = L + (R - L) / 2;
    return tree[v].add + min(getMin(2 * v + 1, L, mid, l, min(mid, r)), getMin(2 * v + 2, mid + 1, R, max(l, mid + 1), r));
}

int n, m;
vector < pair<int, int> > v[MAXN];
long long dp[MAXN];
long long totalSum;

int main() { 

  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);
    v[r].push_back({l, a});
    totalSum += a;
  }

  long long minRem = 0;
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = getMin(0, 0, n + 1, 0, i - 1);
    minRem = min(minRem, dp[i]);
    for (auto p : v[i]) {
      int l = p.first, cost = p.second;
      add(0, 0, n + 1, 0, l - 1, cost);
    }
    add(0, 0, n + 1, i, i, dp[i]);
  }

  cout << totalSum - minRem << endl;

  return 0;
}
