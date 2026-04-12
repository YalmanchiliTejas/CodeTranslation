
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb puch_back
#define mk make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll n, k;

int main() {
  cin >> n >> k;

  if (k == 0) {
    cout << n*n << endl;
    return 0;
  }

  ll ans = 0;
  for (int b = k+1; b <= n; ++b) {
    ans += (n/b) * (b-k);
    if (n%b >= k) ans += (n%b)-k+1;
  }

  cout << ans << endl;

  return 0;
}
