#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int toi(char c){
  if(isdigit(c)) return c - '2';
  if(c == 'T') return 8;
  if(c == 'J') return 9;
  if(c == 'Q') return 10;
  if(c == 'K') return 11;
  if(c == 'A') return 12;
}

int main(){
  char c;
  string deb[4] = {"norst", "east", "south", "west"};
  while(cin>>c && c != '#'){
    int point[2] = {};
    string card[4][13];
    REP(i, 4)REP(j, 13) cin>>card[i][j];
    char d = card[0][0][1];
    REP(i, 13){
      int high = -24;
      int win = -1;
      REP(j, 4){
        string s = card[j][i];
        int n = toi(s[0]);
        if(s[1] == c) n += 13;
        else if(s[1] != d) n -= 13;
        //assert(high != n);
        if(high < n){
          high = n;
          win = j;
        }
      }
      if(i != 12){
        d = card[win][i + 1][1];
      }
      point[win % 2] += 1;
    }
    if(point[0] > point[1]){
      cout<<"NS"<<" "<<point[0] - 6<<endl;
    }else{
      cout<<"EW"<<" "<<point[1] - 6<<endl;
    }
  }
  return 0;
}