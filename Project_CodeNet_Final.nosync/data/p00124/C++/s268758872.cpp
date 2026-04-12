#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Team {
public:
  string name;
  int win;
  int id;
  Team(string name="", int win=0, int id=0) : name(name), win(win), id(id) {}
  bool operator <(const Team &t) const {
    if(win == t.win) return id > t.id;
    else             return win < t.win;
  }
};

int main() {
  bool first = true;
  while(1) {
    int n;
    cin >> n;
    if(n == 0) break;

    Team tm[n];
    for(int i = 0; i < n; i++) {
      int a, b, c;
      cin >> tm[i].name >> a >> b >> c;
      tm[i].win = a*3 + b*0 + c*1;
      tm[i].id = i;
    }
    sort(&tm[0], &tm[n-1]+1);

    if(!first) {
      cout << endl;
    } else {
      first = false;
    }
    for(int i = n-1; i >= 0; i--) {
      cout << tm[i].name << ',' << tm[i].win << endl;
    }

  }
  return 0;
}