#include<bits/stdc++.h>
using namespace std;
const string pp = "23456789TJQKA";

int main()
{
  string S;
  
  while(cin >> S, S != "#") {
    string p[4][13];
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 13; j++) cin >> p[i][j];
    }
    int score[2] = {}, leader = 0;
    for(int i = 0; i < 13; i++) {
      int winner = 0, best = 0;
      for(int j = 0; j < 4; j++) {
        if(p[leader][i][1] != p[j][i][1] && S[0] != p[j][i][1]) continue;
        int point = pp.find(p[j][i][0]);
        if(S[0] == p[j][i][1]) point += 810;
        if(best < point) {
          best = point;
          winner = j;
        }
      }
      leader = winner;
      ++score[winner & 1];
    }
    if(score[0] > score[1]) {
      cout << "NS " << score[0] - 6 << endl;
    } else {
      cout << "EW " << score[1] - 6 << endl;
    }
  }
}