#include <bits/stdc++.h>

using namespace std;

int main()
{
  string ranks = "23456789TJQKA";
  char trump;
  while(cin >> trump, trump != '#'){
    pair<int, char> card[4][13];
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 13; j++){
	string c;
	cin >> c;
	card[i][j].first = ranks.find(c[0]) + 1;
	card[i][j].second = c[1];
      }
    }
    int score[2] = {-6, -6};
    int winner = 0;
    for(int i = 0; i < 13; i++){
      for(int j = 0; j < 4; j++){
	char suit = (card[j][i].second==trump?trump:card[winner][i].second);
	if(card[winner][i].first*(card[winner][i].second==suit) < card[j][i].first*(card[j][i].second==suit)){
	  winner = j;
	}
      }
      score[winner%2]++;
    }
    if(score[0] > score[1]) cout << "NS " << score[0] << endl;
    else cout << "EW " << score[1] << endl;
  }
  return 0;
}