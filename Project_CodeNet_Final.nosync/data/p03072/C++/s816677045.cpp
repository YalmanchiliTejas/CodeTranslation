#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

int main(){
//  ios::sync_with_stdio(false);
//  cin.tie(0);
  int n;
  cin >> n;
  int pre = -1;
  int ans = 0;
  REP(i,n) {
    int a;
    cin >> a;
    if (a >= pre) {
      pre = a;
      ans++;
    }
  }
cout << ans << endl;

  return 0;
}
