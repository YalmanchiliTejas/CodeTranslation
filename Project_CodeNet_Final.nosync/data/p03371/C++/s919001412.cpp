#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = INT_MAX;
  for(int i = 0; i <= 200000; i += 2) {
    int ab = i * c;
    int aa = (x - i / 2) * a;
    int bb = (y - i / 2) * b;
    int value = ab + max(0, aa) + max(0, bb);
    ans = min(ans, value);
  }

  cout << ans << endl;
}
