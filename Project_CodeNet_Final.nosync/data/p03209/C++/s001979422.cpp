#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
ll pa[55], br[55], lg[55];
ll dfs(ll x, ll level){
    if(x==1){
        return 0;
    }else if(x>1 && x< lg[level-1]+1){
        return dfs(x-1, level-1);
    }else if(x==lg[level-1]+1){
        return pa[level-1];
    }else if(x==lg[level-1]+2){
        return (pa[level-1]+1);
    }else if(x<lg[level-1]*2+2){
        return (dfs(x-2-lg[level-1], level-1) + pa[level-1] + 1);
    }else if(x==lg[level-1] * 2 + 2){
        return pa[level] ;
    }else {
        return pa[level];;
    }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,x; cin >> n >> x;
  pa[0] =1;
  br[0] = 0;
  lg[0] = 1;
  FOR(i,1,51){
      pa[i] = pa[i-1] * 2 +1;
      br[i] = pa[i]-1;
      lg[i] = pa[i] + br[i] ;
  }
  ll ans = dfs(x, n);
  cout << ans << endl;

}