#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

#define mp make_pair

int main(int argc, char const* argv[]) {
  int id, score;
  char camma;
  map<int,int> team_list;
  vector<int> score_list;
  
  while (true) {
    cin>>id>>camma>>score;
    if (id==0 && score==0) {
      break;
    }
    team_list.insert(mp(id, score));
    if (count(score_list.begin(), score_list.end(), score) == 0) {
      score_list.push_back(score);
    }
  }
  sort(score_list.begin(), score_list.end(), greater<int>());
  
  int query;
  while (cin>>query) {
    for (int i = 0; i < score_list.size(); i += 1) {
      if (score_list[i] == team_list[query]) {
        cout<<i+1<<endl;
        break;
      }
    }
  }
  
  return 0;
}