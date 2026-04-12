#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

//自作関数 a^n mod MODを求める
int m_pow(int a, int n){
  if(n == 0) return 1;
  if(n % 2 == 0){
    int t = m_pow(a, n / 2);
    return t * t % MOD;
  }
  return a * m_pow(a, n - 1) % MOD;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  string s;

  cin >> s;

  char c = s[0];

  REP(i,3){
    if(c != s[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}