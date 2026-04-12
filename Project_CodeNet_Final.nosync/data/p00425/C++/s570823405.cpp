#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> Dice;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

enum {TOP, FRONT, RIGHT, LEFT, BACK, BOTTOM};
#define rotate_swap(x, a, b, c, d) swap(x[a], x[b]); swap(x[b], x[c]); swap(x[c], x[d]);
void rotate_r(Dice &dice) {rotate_swap(dice, TOP, LEFT, BOTTOM, RIGHT);}
void rotate_l(Dice &dice) {rotate_swap(dice, TOP, RIGHT, BOTTOM, LEFT);}
void rotate_f(Dice &dice) {rotate_swap(dice, TOP, BACK, BOTTOM, FRONT);}
void rotate_b(Dice &dice) {rotate_swap(dice, TOP, FRONT, BOTTOM, BACK);}
void rotate_w(Dice &dice) {rotate_swap(dice, BACK, LEFT, FRONT, RIGHT);}
void rotate_c(Dice &dice) {rotate_swap(dice, BACK, RIGHT, FRONT, LEFT);}
vector<Dice> generate_all(Dice dice) {
  vector<Dice> res;
  rep(i, 6) {
    rep(j, 4) res.push_back(dice), rotate_w(dice);
    i % 2 ? rotate_f(dice) : rotate_r(dice);
  }
  return res;
}

int main() {
  Dice dice(6);
  dice[TOP] = 1;
  dice[FRONT] = 2;
  dice[RIGHT] = 3;
  dice[LEFT] = 4;
  dice[BACK] = 5;
  dice[BOTTOM] = 6;
  vector<Dice> dices = generate_all(dice);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    Dice d = dice;
    int res = 1;
    rep (i, n) {
      string str;
      cin >> str;
      if (str == "North") rotate_b(d);
      if (str == "East") rotate_r(d);
      if (str == "West") rotate_l(d);
      if (str == "South") rotate_f(d);
      if (str == "Right") rotate_w(d);
      if (str == "Left") rotate_c(d);
      res += d[TOP];
    }
    cout << res << endl;
  }
  return 0;
}