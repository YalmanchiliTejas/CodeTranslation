/* monkukui 競技プログラミング用のテンプレート  (ここから) */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
using lnt = long long int;
using Graph = vector<vector<int>>;
using Wgraph = vector<vector<pair<int, long long int>>>;
constexpr long long int INF = 1001001001001001LL;
constexpr long long int MOD = 1000000007LL;
constexpr double PI = 3.1415926535897932;
constexpr long long int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
constexpr long long int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
inline void yes(){ cout << "yes" << endl; }
inline void Yes(){ cout << "Yes" << endl; }
inline void YES(){ cout << "YES" << endl; }
inline void no(){ cout << "no" << endl; }
inline void No(){ cout << "No" << endl; }
inline void NO(){ cout << "NO" << endl; }
inline void possible(){ cout << "possible" << endl; }
inline void Possible(){ cout << "Possible" << endl; }
inline void POSSIBLE(){ cout << "POSSIBLE" << endl; }
inline void impossible(){ cout << "impossible" << endl; }
inline void Impossible(){ cout << "Impossible" << endl; }
inline void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = 1; i <= (n); i++)
#define DREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define SREP(i,s,t) for(int i = s; i < t; i++)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define PB push_back

/* monkukui 競技プログラミング用のテンプレート (ここまで)*/

int main(){
  
  int h, w; cin >> h >> w;
  vector<vector<char>> a(h, vector<char> (w));

  vector<bool> col(h, true);
  vector<bool> row(w, true);
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      cin >> a[i][j];
  
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(a[i][j] == '#') {
        col[i] = false;
        row[j] = false;
      }
    }
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(!col[i] and !row[j]) cout << a[i][j];
    }
    if(!col[i]) cout << endl;
  }
  return 0;
}
