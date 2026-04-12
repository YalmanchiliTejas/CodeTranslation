#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool>    vecbool;
typedef vector<int>     vecint;
typedef vector<ll>      vecll;
typedef vector<string>  vecstr;
typedef vector<vecint>  vec2int;
typedef vector<vecbool> vec2bool;
int dx[4] {-1,+1, 0, 0};
int dy[4] { 0, 0,-1,+1};
int main()
{
  int h, w; cin >> h >> w;
  vecstr s(h);
  REP(i,h){
    cin >> s[i];
  }
  vecint l(h,0), r(h,w);
  REP(i,h){
    REP(j,w){
      if(s[i][j] == '#'){
	l[i] = j;
	break;
      }
    }
    for(int j = w - 1; j >= 0; j --){
      if(s[i][j] == '#'){
	r[i] = j;
	break;
      }
    }
  }
  REP(i, h - 1){
    if(l[i + 1] != r[i]){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
}
