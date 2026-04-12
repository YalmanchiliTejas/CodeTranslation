#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<vector>
 
using namespace std;
 
void North(int* dice){
  int predice[7];
  for(int i = 0 ; i < 7 ; i++) predice[i] = dice[i];
  dice[1] = predice[2];
  dice[2] = predice[6];
  dice[5] = predice[1];
  dice[6] = predice[5];
}

void East(int* dice){
  int predice[7];
  for(int i = 0 ; i < 7 ; i++) predice[i] = dice[i];
  dice[1] = predice[4];
  dice[3] = predice[1];
  dice[4] = predice[6];
  dice[6] = predice[3];
}

void West(int* dice){
  int predice[7];
  for(int i = 0 ; i < 7 ; i++) predice[i] = dice[i];
  dice[1] = predice[3];
  dice[3] = predice[6];
  dice[4] = predice[1];
  dice[6] = predice[4];
}

void South(int* dice){
  int predice[7];
  for(int i = 0 ; i < 7 ; i++) predice[i] = dice[i];
  dice[1] = predice[5];
  dice[2] = predice[1];
  dice[5] = predice[6];
  dice[6] = predice[2];
}

void Right(int* dice){
  int predice[7];
  for(int i = 0 ; i < 7 ; i++) predice[i] = dice[i];
  dice[2] = predice[3];
  dice[3] = predice[5];
  dice[4] = predice[2];
  dice[5] = predice[4];
}

void Left(int* dice){
  int predice[7];
  for(int i = 0 ; i < 7 ; i++) predice[i] = dice[i];
  dice[2] = predice[4];
  dice[3] = predice[2];
  dice[4] = predice[5];
  dice[5] = predice[3];
}

int main(){

  int dice[7];
  int n,score;

  while(1){

    for(int i = 1; i <= 7 ; i++) dice[i] = i; //initialize
    score = 1;

    scanf("%d",&n);

    if(n == 0) break;

    for(int i = 0 ; i < n ; i++){

      std::string s;
      cin >> s;

      if(s[0] == 'N') North(dice);
      else if(s[0] == 'E') East(dice);
      else if(s[0] == 'W') West(dice);
      else if(s[0] == 'S') South(dice);
      else if(s[0] == 'R') Right(dice);
      else if(s[0] == 'L') Left(dice);

      score += dice[1];

    }
    cout << score << endl;
  }
    return 0;
}