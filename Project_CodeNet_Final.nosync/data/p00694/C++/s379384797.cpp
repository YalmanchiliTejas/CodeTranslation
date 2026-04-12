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
struct P{
  int x, y, z;
  P() : x(0), y(0), z(0) {}
  P(int x, int y, int z) : x(x), y(y), z(z) {}
  bool operator < (const P& p) const {
    if(x != p.x) return x < p.x;
    if(y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator == (const P& p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  P operator - (const P& p) const {
    return P(x - p.x, y - p.y, z - p.z);
  }
};
typedef pair<P, P> L;
vector<L> input(){
  int N; cin >> N;
  P label[100] = {};
  bool used[100] = {};
  P cur;
  vector<L> res;
  while(N--){
    string s;
    cin >> s;
    if(isdigit(s[0])){
      int l = atoi(s.c_str());
      if(used[l]){
        cur = label[l];
      }else{
        label[l] = cur;
        used[l] = true;
      }
    }else{
      int dif = (s[0] == '+' ? 1 : -1);
      P next = cur;
      if(s[1] == 'x'){
        next.x += dif;
      }else if(s[1] == 'y'){
        next.y += dif;
      }else if(s[1] == 'z'){
        next.z += dif;
      }else{
        assert(false);
      }
      res.push_back(L(cur, next));
      cur = next;
    }
  }
  return res;
}
void update(P& p, P q){
  p.x = min(p.x, q.x);
  p.y = min(p.y, q.y);
  p.z = min(p.z, q.z);
}
vector<L> normalize(const vector<L>& s){
  P min_p = s[0].first;
  REP(i, s.size()){
    update(min_p, s[i].first);
    update(min_p, s[i].second);
  }
  vector<L> res;
  REP(i, s.size()){
    res.push_back(L(s[i].first - min_p, s[i].second - min_p));
    if(res[i].second < res[i].first) swap(res[i].first, res[i].second);
  }
  sort(res.begin(), res.end());
  return res;
}
void rotate_x(vector<L>& s){
  REP(i, s.size()){
    s[i].first = P(s[i].first.x, -s[i].first.z, s[i].first.y);
    s[i].second = P(s[i].second.x, -s[i].second.z, s[i].second.y);
  }
}
void rotate_y(vector<L>& s){
  REP(i, s.size()){
    s[i].first = P(s[i].first.z, s[i].first.y, -s[i].first.x);
    s[i].second = P(s[i].second.z, s[i].second.y, -s[i].second.x);
  }
}
void rotate_z(vector<L>& s){
  REP(i, s.size()){
    s[i].first = P(-s[i].first.y, s[i].first.x, s[i].first.z);
    s[i].second = P(-s[i].second.y, s[i].second.x, s[i].second.z);
  }
}
int main(){
  while(true){
    vector<L> k1 = input();
    if(k1.empty()) break;
    vector<L> k2 = input();
    k2 = normalize(k2);

    bool is_equal = false;
    for(int k = 0; k < 6; k++){
      if(k % 2 == 0) rotate_x(k1);
      else rotate_y(k1);
      for(int i = 0; i < 4; i++){
        rotate_z(k1);
        k1 = normalize(k1);
        if(k1 == k2){
          is_equal = true;
          //goto OUTPUT;
        }
      }
    }

OUTPUT:
    if(is_equal) cout << "SAME" << endl;
    else cout << "DIFFERENT" << endl;
  }
  return 0;
}