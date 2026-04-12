#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  int a[n][26] = {};
  REP(i,n){
    string s;
    cin >> s;
    REP(j,s.size()){
      a[i][s[j]-'a']++;
    }
  }
  
  REP(i,26){
    int x = MOD;
    REP(j,n){
      x = min(x,a[j][i]);
    }
    while(x != 0){
      cout << (char)(i+'a');
      x--;
    }
  }
  
  cout << endl;

  return 0;
}