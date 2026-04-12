#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

char trump;
pair<char, char> hands[4][13];
bool used[4][13];
char dealerSuit;

int val(char c){
  if('2' <= c && c <= '9') return c - '0';
  if(c == 'T') return 10;
  if(c == 'J') return 11;
  if(c == 'Q') return 12;
  if(c == 'K') return 13;
  if(c == 'A') return 14;
}

main(){
  while(cin >> trump){
    if(trump == '#') break;
    for(int i=0;i<4;i++){
      for(int j=0;j<13;j++){
	cin >> hands[i][j].first >> hands[i][j].second;
      }
    }
    int dealer = 3;
    int cntEw = 0, cntNs = 0;
    for(int i=0;i<13;i++){
      dealerSuit = hands[dealer][i].second;
      int turn = dealer;
      int value[4];
      for(int k=0;k<4;k++){
	value[k] = val(hands[k][i].first);
      }
      int winner;
      int valMax = -1;
      for(int j=0;j<4;j++){
	if(hands[j][i].second != trump) continue;
	if(valMax < value[j]){
	  winner = j;
	  valMax = value[j];
	}
      }
      if(valMax == -1){
	for(int j=0;j<4;j++){
	  if(hands[j][i].second != dealerSuit) continue;
	  if(valMax < value[j]){
	    winner = j;
	    valMax = value[j];
	  }
	}
	if(valMax == -1){
	  for(int j=0;j<4;j++){
	    if(valMax < value[j]){
	      winner = j;
	      valMax = value[j];
	    }
	  }
	}
      }
      dealer = winner;
      if(winner == 0 || winner == 2){
	cntNs++;
      }else{
	cntEw++;
      }
      /*if(winner == 0){
	cout << "north" << endl;
      }else if(winner == 1){
	cout << "east" << endl;
      }else if(winner == 2){
	cout << "south" << endl;
      }else{
	cout << "west" << endl;
	}*/
    }
    if(cntEw > cntNs){
      cout << "EW " << cntEw%6 << endl;
    }else{
      cout << "NS " << cntNs%6 << endl;
    }
  }
  return 0;
}