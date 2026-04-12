#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

// dice<hoge> di(arr); ÈÇÆé¾·é
// ±ÌÆ«AarrÍ hoge di[6];Åé¾³êÄ¨èAid ÌlÌÉÊÌlªi[³êÄ¢éKvª éB
// á¦ÎAid[TOP] = 3 ÈçÎAdi[3] ÌlªTOPÉÝè³êéB
// TCRÆµÄµ¢©Ç¤©Ì»èÉ equivalent_to ðg¤B
enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };
template <class T>
class dice {
public:
  dice(T *v) {
    id[TOP] = 0; id[FRONT] = 1; id[LEFT] = 2;
    id[RIGHT] = 3; id[BACK] = 4; id[BOTTOM] = 5;
    REP(i,6)
      var[i] = v[i];
  }
  T& operator[] (FACE f) { return var[id[f]]; }
  const T& operator[] (FACE f) const { return var[id[f]]; }
  bool operator==(const dice<T>& b) const {
    const dice<T> &a = *this;
    return a[TOP] == b[TOP] && a[BOTTOM] == b[BOTTOM] &&
           a[FRONT] == b[FRONT] && a[BACK] == b[BACK] &&
           a[LEFT] == b[LEFT] && a[RIGHT] == b[RIGHT];
  }
  void roll_x() { roll(TOP, BACK, BOTTOM, FRONT); }
  void roll_y() { roll(TOP, LEFT, BOTTOM, RIGHT); }
  void roll_z() { roll(FRONT, RIGHT, BACK, LEFT); }
  vector<dice> all_rolls() {
    vector<dice> ret;
    for (int k = 0; k < 6; (k&1?roll_y():roll_x()),++k)
      for (int i = 0; i < 4; roll_z(), ++i)
        ret.push_back(*this);
    return ret;
  }
  bool equivalent_to(const dice& di) {
    for (int k = 0; k < 6; (k&1?roll_y():roll_x()),++k)
      for (int i = 0; i < 4; roll_z(), ++i)
        if (*this == di) return true;
    return false;
  }
private:
  void roll(FACE a, FACE b, FACE c, FACE d) {
    int tmp = id[a];
    id[a] = id[b]; id[b] = id[c];
    id[c] = id[d]; id[d] = tmp;
  }
  T var[6];
  int id[6];
};


int main() {
  int arr[] = {1,2,4,3,5,6};
  int n;
  while(cin >> n, n) {
    dice<int> di(arr);
    int res = 0;
    REP(i,n) {
      string s;
      cin >> s;
      if (s == "North") {
        di.roll_x();di.roll_x();di.roll_x();
      } else if (s == "East") {
        di.roll_y();
      } else if (s == "West") {
        di.roll_y();di.roll_y();di.roll_y();
      } else if (s == "South") {
        di.roll_x();
      } else if (s == "Right") {
        di.roll_z();
      } else {
        di.roll_z();di.roll_z();di.roll_z();
      }
      res += di[TOP];
    }
    cout << res+1<< endl;
  }
}