#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > Team_Data;
int Team_Rank[100];

int main(void){
  int team_id, score;
  while(true){
    scanf("%d,%d", &team_id, &score);
    if(team_id == 0 && score == 0){
      break;
    }
    Team_Data.push_back(pair<int, int>(score, team_id));
  }

  sort(Team_Data.rbegin(), Team_Data.rend());

  Team_Rank[Team_Data[0].second] = 1;
  int nowScore = Team_Data[0].first;
  int nowRank = 1;
  
  for(int i = 1; i < Team_Data.size(); i++){
    if(Team_Data[i].first == nowScore){
      Team_Rank[Team_Data[i].second] = nowRank;
    }else{
      nowRank++;
      nowScore = Team_Data[i].first;
      Team_Rank[Team_Data[i].second] = nowRank;
    }
  }
  
  int ref;
  while(cin >> ref){
    cout << Team_Rank[ref] << endl;
  }
  return 0;
}