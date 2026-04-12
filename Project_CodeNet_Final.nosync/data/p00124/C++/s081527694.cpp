#include <bits/stdc++.h>
using namespace std;

struct Team {
  int point;
  string name;
  Team(string name, int win, int lose, int draw)
      : name(name), point(win * 3 + draw) {}
  void print() { cout << name << "," << point << endl; }
  bool operator>(const Team& t) const { return point > t.point; }
};

int main() {
  int n;
  int nlf = 0;
  while (scanf("%d", &n), n) {
    if (nlf++) puts("");

    vector<Team> ts;
    for (int i = 0; i < n; i++){
      string name;
      int win, lose, draw;
      cin >> name >> win >> lose >> draw;
      ts.push_back(Team(name, win, lose, draw));
    }
    stable_sort(ts.begin(), ts.end(), greater<Team>());
    for (int i = 0; i < n; i++) ts[i].print();
  }
  return (0);
}