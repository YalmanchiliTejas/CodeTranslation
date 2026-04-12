#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Team {
public:
  int id;
  int score;
  Team(int id, int score) : id(id), score(score) {}
  bool operator < (const Team &t) const {
    return score > t.score;
  }
};
int main() {
  vector<Team> v;

  while(1) {
    int a, b;
    scanf("%d,%d", &a, &b);
    if(a == 0 && b == 0) break;
    v.push_back(Team(a, b));
  }
  sort(v.begin(), v.end());

  int id;
  while(cin >> id) {
    int before = -1, rank = 0;
    for(int i = 0; i < v.size(); i++) {
      if(before != v[i].score) rank++;
      if(v[i].id == id) {
	cout << rank << endl;
	break;
      }
      before = v[i].score;
    }
  }
  return 0;
}