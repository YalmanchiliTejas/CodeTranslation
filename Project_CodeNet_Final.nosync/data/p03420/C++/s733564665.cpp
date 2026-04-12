#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

int main() {
  int n,k;
  S2(n,k);
  LL ans = 0;
  rep(i,max(k,1),n+1) {
    ans += n - i;
    int tot = i - k;
    ans += ((n / i) - 1) * 1LL * tot;
    ans += max((n % i) - k + 1, 0);
  }
  cout << ans << "\n";
  return 0;
}
