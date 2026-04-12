#include <iostream>
#include <set>

using namespace std;

const string YES = "Possible";
const string NO = "Impossible";

int main() {
  int H, W;
  char a;
  cin >> H >> W;
  bool cond = true;
  set<int> s;
  for (auto i = 0; i != H; ++i) {
    for (auto j = 0; j != W; ++j) {
      cin >> a;
      if(a == '#' && !s.insert(i+j).second) {
        cond = false;
        break;
      }
    }
  }
  cout << (cond ? YES : NO) << endl;
}
