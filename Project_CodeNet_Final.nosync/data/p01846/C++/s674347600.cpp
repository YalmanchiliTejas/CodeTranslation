#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<tuple>
#include<utility>
#include<vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define REP(i, n)  for(int i=0; i<(int)(n); i++)
#define REPS(i, n)  for(int i=1; i<=(int)(n); i++)
#define PER(i, n) for(int i=(int)(n)-1; i>= 0; i--)
#define PERS(i, n)  for(int i=(int)(n)-1; i>0; i--)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
#define RFOR(i, c)  for(__typeof((c).rbegin()) i=(c).rbegin(); i!=(c).end(); i++)
#define ALL(container)  (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) (container).size()
#define FILL0(n)  setfill('0') << right << setw(n)
#define mp(a, b)  make_pair(a, b)
#define toLower(c)  c+0x20
#define toUpper(c)  c-0x20
#define pb  push_back
#define eb  emplace_back

const int INF = 1<<28;
const int MOD = 1000000007;

vector<string> split(const string &str, char sep){
  vector<string>  v;
  stringstream ss(str);
  string buffer;
  while(getline(ss, buffer, sep)){
    v.push_back(buffer);
  }
  return v;
}

int main(){
  while(true){
    string s; cin >> s;
    if(s == "#")  break;
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--;  b--;  c--;  d--;
    vector<string> ss = split(s, '/');
    vector<string> board(ss.size(), "");
    rep(i, 0, board.size()){
      for(const char& c:ss[i]){
        if(c=='b')  board[i]+='b';
        else{
          int num = c-'0';
          string tmp(num, '.');
          board[i]+=tmp;
        }
      }
    }
    char tmpc = board[a][b];
    board[a][b] = board[c][d];
    board[c][d] = tmpc;

    string ans = "";
    rep(i, 0, board.size()){
      int dotn = 0;
      rep(j, 0, board[i].length()){
        if(board[i][j]=='b'){
          if(dotn > 0)  {
            ans += (char)(dotn+'0');
            dotn = 0;
          }
          ans += 'b';
        }else{
          dotn++;
        }
      }
      if(dotn > 0)  ans += (char)(dotn+'0');
      if(i!=board.size()-1) ans += '/';
    }
    cout << ans << endl;
  }
  return 0;
}

