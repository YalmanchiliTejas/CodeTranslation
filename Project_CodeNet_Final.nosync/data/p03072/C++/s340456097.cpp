#include <bits/stdc++.h>
#define REP(i,k,n) for(int(i)=(k);(i)<(n);++(i))
#define ALL(x) (x).begin(),(x).end()
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)
using namespace std;
typedef long long ll;

int N;
vector<int> H;

int main()
{
  cin >> N;
  H.resize(N);
  REP(i,0,N) cin >> H[i];

  int ans = 1;
  REP(i,1,N) {
    bool flag = true;
    REP(j,0,i) {
      if (H[j] > H[i]) {
        flag = false; break;
      }
    }
    if (flag) ++ans;
  }
  cout << ans << endl;

  return 0;
}
