#include <iostream>
#include <algorithm>
using namespace std;

struct Team {
  int score, id;
  string name;
  bool operator < (const Team &t) const {
    if(score != t.score) return score > t.score;
    return id < t.id;
  }
};

int n;
Team t[10];

int main() {
  while(cin >> n && n) {
    for(int i = 0; i < n; ++i) {
      int a, b, c;
      cin >> t[i].name >> a >> b >> c;
      t[i].score = a*3 + c;
      t[i].id = i;
    }
    sort(t, t+n);
    static int tc = 0;
    if(tc++) cout << endl;
    for(int i = 0; i < n; ++i) {
      cout << t[i].name << "," << t[i].score << endl;
    }
  }
  return 0;
}