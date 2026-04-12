#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
  ll H,W;
  cin >> H >> W;
  string board[H];
  rep(i,H) cin >> board[i];

  int x = 0;
  int y = 0;
  while(true){
    board[y][x] = 'x';
    if(x == W-1 && y == H-1) break;
    if(board[y][x+1] == '#' && board[y+1][x] == '#'){
      cout << "Impossible" << endl;
      return 0;
    }else if(x+1 < W && board[y][x+1] == '#'){
      x++;
    }else if(y+1 < H && board[y+1][x] == '#'){
      y++;
    }else{
      cout << "Impossible" << endl;
      return 0;
    }
  }

  rep(i,H)rep(j,W){
    if(board[i][j] == '#'){
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  return 0;
}
