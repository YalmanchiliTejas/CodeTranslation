#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = 2e9;
const int MAX_N = 200000;
const int MAX_M = 200000;

int N;
vi a, b;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp; cin >> tmp;
    a.pb(tmp);
  }
  b = a;
  sort(b.begin(), b.end());
  for (int i = 0; i < N; i++) {
    if (a[i] <= b[N/2-1]) {
      cout << b[N/2] << endl;
    } else {
      cout << b[N/2-1] << endl;
    }
  }
  return 0;
}
