#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(void){
  int H, W;
  cin >> H >> W;
  bool board[H+1][W+1];

  for(int i=0;i<H;i++){
    string s;
    cin >> s;
    for(int j=0;j<W;j++){
      if(s[j] == '#') board[i][j] = true;
      else board[i][j] = false;
    }
  }

  for(int i=0;i<=H;i++) board[i][W] = false;
  for(int i=0;i<=W;i++) board[H][i] = false;

  int cur_x, cur_y;
  cur_x = 0;
  cur_y = 0;
  while(!(cur_x == H-1 && cur_y == W-1)){
    board[cur_x][cur_y] = false;
    if(board[cur_x+1][cur_y] == false && board[cur_x][cur_y+1] == false){
      cout << "Impossible" << endl;
      return 0;
    }
    if(board[cur_x+1][cur_y] == true && board[cur_x][cur_y+1] == true){
      cout << "Impossible" << endl;
      return 0;
    }
    if(board[cur_x+1][cur_y] == true && board[cur_x][cur_y+1] == false){
      cur_x++;
    }
    else if(board[cur_x+1][cur_y] == false && board[cur_x][cur_y+1] == true){
      cur_y++;
    }
  }
  board[H-1][W-1] = false;


  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(board[i][j]){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }


  cout << "Possible" << endl;
  return 0;
}
