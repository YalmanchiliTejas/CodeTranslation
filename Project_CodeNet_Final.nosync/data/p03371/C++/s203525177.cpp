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
ll a, b, c, x, y;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> a >> b >> c >> x >> y;

  ll ans = 0;
  if(a + b > c * 2) {
    if(y > x) {
      swap(x, y); swap(a, b);
    }
    ans += y * 2 * c;
    if(a >= c * 2) ans += ((x - y) * 2) * c;
    else ans += (x - y) * a;

  } else {
    ans += x * a;
    ans += y * b;
  }

  cout << ans << endl;
}
