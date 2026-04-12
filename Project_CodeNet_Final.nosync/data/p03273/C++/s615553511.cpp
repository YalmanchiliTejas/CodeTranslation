#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int h,w;
int checkT(vvi &c, int x){
  rep(i, h){
    if(c[i][x]) return 0;
  }
  return 1;
}
int checkY(vvi &c, int y){
  rep(i, w){
    if(c[y][i]) return 0;
  }
  return 1;
}
int main(){
  cin >> h >> w;
  vvi a(h, vi(w));
  rep(y, h){
    rep(x, w){
      char c;
      cin >> c;
      a[y][x] = (c == '#') ? 1 : 0;
    }
  }
  rep(y, h){
    rep(x, w){
      if(checkY(a, y)) break;
      if(!checkT(a, x)){
        char ans = (a[y][x] ? '#' : '.');
        cout << ans;
      }
    }
    if(!checkY(a, y)) cout << endl;
  }
}