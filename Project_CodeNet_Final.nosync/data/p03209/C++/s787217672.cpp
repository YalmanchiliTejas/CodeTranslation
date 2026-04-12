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
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;
// << fixed << setprecision
// --------------------------------------
ll n, x;
ll p[55];
ll tot[55];

ll rec(ll n, ll x) {
  if(x >= tot[n]) {
    return p[n];
  } else if(x <= 1) {
    return 0;
  } else if(x <= tot[n] / 2) {
    return rec(n - 1, x - 1);
  } else {
    return rec(n - 1, x - 1) + 1 + rec(n - 1, x - ((tot[n] + 1) / 2));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> x;

  p[0] = 1, tot[0] = 1;
  REP(i, n) {
    p[i + 1] = p[i] * 2 + 1;
    tot[i + 1] = tot[i] * 2 + 3;
  }

  cout << rec(n, x) << endl;
}
