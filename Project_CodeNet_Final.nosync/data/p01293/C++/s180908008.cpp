#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main() {
  while(1){
    string trump;
    cin>>trump;
    if(trump=="#") break;
    int t_suit = 0;
    switch(trump[0]) {
      case 'S': t_suit = 0; break;
      case 'H': t_suit = 1; break;
      case 'D': t_suit = 2; break;
      case 'C': t_suit = 3; break;
    }
    vector<vector<pair<int,int>>> h(13,vector<pair<int,int>>(4));
    REP(i,4)REP(j,13) {
      string card;
      cin>>card;
      int num=0, suit=0;
      if('2' <= card[0] && card[0] <= '9')
        num = card[0] - '0';
      else {
        switch(card[0]) {
          case 'T': num = 10; break;
          case 'J': num = 11; break;
          case 'Q': num = 12; break;
          case 'K': num = 13; break;
          case 'A': num = 14; break;
        }
      }
      switch(card[1]) {
        case 'S': suit = 0; break;
        case 'H': suit = 1; break;
        case 'D': suit = 2; break;
        case 'C': suit = 3; break;
      }
      h[j][i] = make_pair(num, suit);
    }
    int beg = 0;
    int pt = 0;
    REP(i,13) {
      int led = h[i][beg].second;
      int nbeg = beg;
      pair<int,int> win(h[i][beg]);
      REP(j,4) {
        if (h[i][j].second == t_suit) {
          if (win.second != t_suit || win.first < h[i][j].first) {
            win = h[i][j];
            nbeg = j;
          }
        } else if (h[i][j].second == led) {
          if (win.second != t_suit && win.first < h[i][j].first) {
            win = h[i][j];
            nbeg = j;
          }
        }
      }
      if ((nbeg % 2) == 0) ++pt;
      beg = nbeg;
    }
    if (pt > 6)
      cout << "NS " << (pt - 6) << endl;
    else
      cout << "EW " << ((13 - pt) - 6) << endl;
  }
  return 0;
}