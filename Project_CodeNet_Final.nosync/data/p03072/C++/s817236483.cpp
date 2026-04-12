#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

signed main()
{
  int n;
  cin >> n;

  vi h(n);
  rep(i, 0, n){
    cin >> h[i];
  }

  int ans = 0, m = 0;
  rep(i, 0, n){
    if(m <= h[i]){
      ans++;
      m = h[i];
    }
  }

  cout << ans << endl;

  return 0;
}
