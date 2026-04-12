#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  s+=s[0],s+=s[1];
  vector<int> v(n+2);
  rep(i,2){
    rep(j,2){
      v.clear();
      v.resize(n+2);
      v[0]=i,v[1]=j;
      for(int k=2;k<n+2;k++){
        v[k]=(v[k-2]^v[k-1]);
        if(s[k-1]=='x')v[k]=1-v[k];
      }
      if(v[0]==v[n] && v[1]==v[n+1]){
        rep(i,n){
          if(v[i]==0)cout << 'S';
          else cout << 'W';
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}