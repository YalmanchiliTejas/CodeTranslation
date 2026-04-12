#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 1<<50LL
#define fst first
#define snd second
#define pb push_back
#define int long long
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(int itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(int itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<ll,ll> P;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  
  string s[n];
  REP(i,n) cin >> s[i];
  
  int cnt = 0;
  REP(i,n){
    REP(j,m){
      if(s[i][j] == '#') cnt++;
    }
  }
  
  if(cnt == n+m-1) cout << "Possible" << endl;
  else			   cout << "Impossible" << endl;

  return 0;
}