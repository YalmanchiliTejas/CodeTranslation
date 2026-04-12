#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

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

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int x[2],y[2];
  while(true){
    cin >> s;
    if(s == "#") break;
    cin >> y[0] >> x[0] >> y[1] >> x[1];
    y[0]--;
    y[1]--;
    x[0]--;
    x[1]--;

    vector<vector<char>> board;
    vector<char> line;
    rep(i,s.size()){

      if(isdigit(s[i])){
        int lim = s[i] - '0';
        rep(j,lim){
          line.push_back('.');
        }
      }
      else if(s[i] == 'b'){
        line.push_back('b');
      }
      else if(s[i] == '/'){
        board.push_back(line);
        line.clear();
      }
      if(i == s.size() - 1) board.push_back(line);
    }

    // rep(i,board.size()){
    //   rep(j,board[0].size()){
    //     cout << board[i][j];
    //   }
    //   cout << endl;
    // }
    board[y[0]][x[0]] = '.';
    board[y[1]][x[1]] = 'b';
    string ans = "";
    rep(i,board.size()){
      int cnt = 0;
      rep(j,board[0].size()){
        if(board[i][j] == '.') cnt++;
        if(board[i][j] == 'b'){
          if(cnt > 0)ans += toString(cnt);
          ans.push_back('b');
          cnt = 0;
        }
      }
      if(cnt > 0) ans += toString(cnt);
      ans.push_back('/');
    }
    ans.pop_back();
    cout << ans << endl;
  }

  return 0;
}

