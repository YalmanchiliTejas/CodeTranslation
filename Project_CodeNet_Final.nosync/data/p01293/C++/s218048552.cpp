#include<iostream>
#include<cstring>
using namespace std;
int num_v[4];

int order(char c){
  char a[13] = {'2', '3', '4', '5', '6', '7', '8',
                '9', 'T', 'J', 'Q', 'K', 'A'};
  for (int i = 0; i < 13; i++) {
    if(c == a[i])return i+1;
  }
  return 0;
}

int winner(string suit, char mark, string card[4], int& pos){
  int match_suit[4];
  int Max = 0, tpos = -1;
  char m = 0;
  for (int i = pos; i < pos + 4; i++) {
    int p = i%4;
    if(suit[0] == card[p][1])match_suit[p] = 2;
    else if(mark == card[p][1])match_suit[p] = 1;
    else match_suit[p] = 0;
  }
  for (int i = pos; i < pos + 4; i++) {
    int p = i%4;
    //    std::cout << match_suit[p] << " ";
    if(Max < match_suit[p])Max = match_suit[p];
  }
  //  std::cout << std::endl;
  for (int i = pos; i < pos + 4; i++) {
    int p = i%4;
    if(match_suit[p] == Max && order(m) < order(card[p][0])){
      m = card[p][0];
      tpos = p;
    }
  }
  //  std::cout << tpos << std::endl;
  return pos = tpos;
}


int main(){
  string suit;
  while(cin >> suit){
    if(suit == "#")break;
    string card[4][13];//N, E, S, W
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        cin >> card[i][j];
      }
    }
    memset(num_v, 0, sizeof(num_v));
    int pos = 0;
    for (int i = 0; i < 13; i++) {
      string tmp[4] = {card[0][i],
                       card[1][i],
                       card[2][i],
                       card[3][i]};
      //std::cout << card[pos][i] << std::endl;
      num_v[winner(suit, card[pos][i][1], tmp, pos)]++;
    //   for (int i = 0; i < 4; i++) {
    //     char t[4] = {'N', 'E', 'S', 'W'};
    //     std::cout << t[i] << " " << num_v[i] << "/";
    //   }
    //   std::cout << std::endl;
    }

    if(num_v[0] + num_v[2] < num_v[1] + num_v[3]){
      std::cout << "EW " << num_v[1] + num_v[3] - 6 << std::endl;
    }else{
      std::cout << "NS " << num_v[0] + num_v[2] - 6 << std::endl;
    }
  }
  return 0;
}