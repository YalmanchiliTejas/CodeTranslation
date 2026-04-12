#include <bits/stdc++.h>
using namespace std;
int main(){
  while (1){
    char trump;
    cin >> trump;
    if (trump == '#'){
      break;
    }
    vector<vector<int>> rank(4, vector<int>(13));
    vector<vector<char>> suit(4, vector<char>(13));
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 13; j++){
        char r, s;
        cin >> r >> s;
        if (2 <= 'r' && r <= '9'){
          rank[i][j] = r - '1';
        }
        if (r == 'T'){
          rank[i][j] = 9;
        }
        if (r == 'J'){
          rank[i][j] = 10;
        }
        if (r == 'Q'){
          rank[i][j] = 11;
        }
        if (r == 'K'){
          rank[i][j] = 12;
        }
        if (r == 'A'){
          rank[i][j] = 13;
        }
        suit[i][j] = s;
      }
    }
    int NS = 0;
    int EW = 0;
    int lead_player = 0;
    for (int i = 0; i < 13; i++){
      char lead = suit[lead_player][i];
      vector<int> s(4);
      for (int j = 0; j < 4; j++){
        if (suit[j][i] == trump){
          s[j] = rank[j][i] + 13;
        } else if (suit[j][i] == lead){
          s[j] = rank[j][i];
        } else {
          s[j] = 0;
        }
      }
      int next = 0;
      for (int j = 0; j < 4; j++){
        if (s[j] > s[next]){
          next = j;
        }
      }
      if (next % 2 == 0){
        NS++;
      } else {
        EW++;
      }
      lead_player = next;
    }
    if (NS > 6){
      cout << "NS " << NS - 6 << endl;
    } else {
      cout << "EW " << EW - 6 << endl;
    }
  }
}
