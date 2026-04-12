#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
ll n, k;
ll a[51], b[51];
ll rec(ll y, ll x) {
  if(x == 1) return y == 0 ? 1 : 0;
  else if(a[y] <= x) return b[y];
  else if(a[y] / 2 + 1 == x) return b[y - 1] + 1;
  else if(a[y] / 2 + 1 < x && x < a[y]) return b[y - 1] + 1 + rec(y - 1, x - (a[y] / 2 + 1));
  else return rec(y - 1, x - 1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  a[0] = 1; b[0] = 1;
  FOR(i, 1, n + 1) {
    a[i] = 2LL * a[i - 1] + 3;
    b[i] = 2LL * b[i - 1] + 1;
  }

  cout << rec(n, k) << endl;
}
