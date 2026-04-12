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
int n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  ll ans = 0;
  if(n % 2 == 0) {
    vector<int> t;
    REP(i, n / 2) {
      t.push_back(a[n / 2 + i]);
      t.push_back(a[i]);
    }

    REP(i, n - 1) ans += abs(t[i + 1] - t[i]);
  } else {
    vector<int> t1, t2;
    t1.push_back(a[n / 2]);
    t2.push_back(a[n / 2]);
    REP(i, n / 2) {
      t1.push_back(a[n - (i + 1)]);
      t1.push_back(a[i]);
      t2.push_back(a[i]);
      t2.push_back(a[n - (i + 1)]);
    }

    ll ans1 = 0, ans2 = 0;
    REP(i, n - 1) {
      ans1 += abs(t1[i + 1] - t1[i]);
      ans2 += abs(t2[i + 1] - t2[i]);
    }
    ans = max(ans1, ans2);
  }

  cout << ans << endl;
}
