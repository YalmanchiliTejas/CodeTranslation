#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for(long long i = (n-1);i>=0;i--)
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
  string s;
  
  cin >> n >> s;
  vector <int>SW[4];
  
  REP(i,4)
    SW[i].resize(n);
  
  SW[0][0] = SW[0][1] = SW[1][0] = SW[2][1] = 1; // S
  SW[1][1] = SW[2][0] = SW[3][0] = SW[3][1] = -1; // W
  
  //最初２匹を決め打ち
  REP(i,4){
    FOR(j,1,n-1){
      if(s[j] == 'o'){
        if(SW[i][j] == 1) SW[i][j+1] = SW[i][j-1];
        else		      SW[i][j+1] = -SW[i][j-1];
      }
      else{
        if(SW[i][j] == 1) SW[i][j+1] = -SW[i][j-1];
        else			  SW[i][j+1] = SW[i][j-1];
      }
    }
    //矛盾チェック; n番目と1番目
    if(   SW[i][n-1] == 1 && s[n-1] == 'o' && SW[i][n-2] == SW[i][0]
        ||SW[i][n-1] == 1 && s[n-1] == 'x' && SW[i][n-2] != SW[i][0]
        ||SW[i][n-1] == -1 && s[n-1] == 'o' && SW[i][n-2] != SW[i][0]
        ||SW[i][n-1] == -1 && s[n-1] == 'x' && SW[i][n-2] == SW[i][0]) {

      if( SW[i][0] == 1 && s[0] == 'o' && SW[i][n-1] == SW[i][1]
        ||SW[i][0] == 1 && s[0] == 'x' && SW[i][n-1] != SW[i][1]
        ||SW[i][0] == -1 && s[0] == 'o' && SW[i][n-1] != SW[i][1]
        ||SW[i][0] == -1 && s[0] == 'x' && SW[i][n-1] == SW[i][1]){
        
      REP(j,n){
        if(SW[i][j] == 1) cout << "S";
        else		   cout << "W";
      }
      cout << endl;
      return 0;
    }
  }
  }
  
  cout << -1 << endl;

  return 0;
}
