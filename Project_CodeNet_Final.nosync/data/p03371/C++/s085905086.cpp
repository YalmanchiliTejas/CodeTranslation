#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <tuple>
#include <complex>
#include <cassert>
#include <exception>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz size()
#define print(X) cout << (X) << "\n"
static const int INF = 1e+9+7;
ll n,m,l;
string s,t;
ll d[200010],dp[1010][1010];
double w[1000],v[1000];
double box[200010];
char field[200][200];

int main(){
  ll x,y;
  ll ans = 0;
  cin >> n >> m >> l >> x >> y;
  ll ans2 = 0;
  {
    ans2 += max(x, y) * 2 * l;
    if(max(x , y) % 2)ans2 += 2 * l;
  }
  {
    if(n + m > 2 * l){
      ans += 2 * min(x,y) * l;
      ll p = min(x,y);
      x-= p;
      y-= p;
    }
    if(x > 0)ans += x * n;
    if(y > 0)ans += y * m;
  }
  // print(ans);
  // print(ans2);
  print(min(ans,ans2));
  return 0;
}
