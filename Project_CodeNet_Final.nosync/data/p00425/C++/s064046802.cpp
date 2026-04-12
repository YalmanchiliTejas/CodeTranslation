#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

#define UP    0
#define DOWN  1
#define FORE  2
#define BACK  3
#define RIGHT 4
#define LEFT  5

struct Dice
{
  int face[6];
  Dice(){}
  Dice(int up, int down, int fore, int back, int right, int left)
  {
    face[UP] = up; face[DOWN] = down;
    face[FORE]  = fore; face[BACK] = back;
    face[RIGHT] = right; face[LEFT] = left;
  }
  void roll(int a, int b, int c, int d) {
    swap(face[a], face[c]);
    swap(face[b], face[d]);
    swap(face[c], face[d]);
  }
  void roll2fore() { roll(FORE, BACK, UP, DOWN); }
  void roll2back() { roll(BACK, FORE, UP, DOWN); }
  void roll2right() { roll(RIGHT, LEFT, UP, DOWN); }
  void roll2left() { roll(LEFT, RIGHT, UP, DOWN); }
  void rotate_clockwise() { roll(FORE, BACK, RIGHT, LEFT); }
  void rotate_counterclockwise() { roll(FORE, BACK, LEFT, RIGHT); }
  void print_face()
  {
    printf("UP   : %d\n", face[UP]);
    printf("DOWN : %d\n", face[DOWN]);
    printf("FORE : %d\n", face[FORE]);
    printf("BACK : %d\n", face[BACK]);
    printf("RIGHT: %d\n", face[RIGHT]);
    printf("LEFT : %d\n", face[LEFT]);
  }
};



signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n;
  while(cin >> n, n) {
    Dice dice(1, 6, 2, 5, 3, 4);
    int ans = 1;
    rep(i, n) {
      string s;
      cin >> s;
      switch(s[0]) {
      case 'N': dice.roll2back(); break;
      case 'E': dice.roll2right(); break;
      case 'S': dice.roll2fore(); break;
      case 'W': dice.roll2left(); break;
      case 'R': dice.rotate_clockwise(); break;
      case 'L': dice.rotate_counterclockwise(); break;
      }
      ans += dice.face[UP];
    }
    cout << ans << endl;
  }

  return 0;
}