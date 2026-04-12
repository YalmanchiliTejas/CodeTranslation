#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REP1(i, n) for(int i = 1; i <= (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pi;
typedef queue<pi> Qpi;
typedef pair<ll, ll> pll;
typedef queue<pll> Qpll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const int mod = 1000000007;
// 小数点　<< fixed << setprecision(0) <<
// sort降順　sort(ALL(),greater<int>());
// 円周率　M_PI
// 文字判定　isupper islower
// 順列　do {} while(next_permutation(ALL(X)));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct edge {
    int from; //出発点
    int to;   //到達点
    int cost; //移動コスト
};
typedef struct edge se;
typedef vector<edge> ve;
unsigned euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) return euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans=a*x+b*y,temp;
  REP1(i,max(x,y)) {
    if(i<=min(x,y)) {
      ans=min(ans,ans-a-b+2*c);
    } else {
      if(x>y) {
        ans=min(ans,ans-a+2*c);
      } else {
        ans=min(ans,ans-b+2*c);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
