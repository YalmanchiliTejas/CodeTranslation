#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;
/* テンプレートここまで */

int main() {
  ll N, K;
  cin >> N >> K;

  if(K==0){
    cout << (ll)N*N << endl;
    return 0;
  }

  ll ans = 0;
  FOR(b, K+1, N+1) {
    ans += b - K;
    if(K > N%b){
      ans += ((N-K)/b) * (b-K);
    }else{
      ans += (N%b - K +1) * ((N-K)/b) + (b - (N%b)-1) * ((N-K)/b - 1);
    }
    //DUMP(ans);
  }

  cout << ans << endl;
}
