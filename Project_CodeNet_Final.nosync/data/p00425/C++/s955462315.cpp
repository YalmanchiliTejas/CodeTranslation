#include<iostream>

using namespace std;

int dice[6];
//0->top, 1->bottom, 2->north 3->south,4->east, 5->west

void init(){
  dice[0] = 1;
  dice[1] = 6;
  dice[2] = 5;
  dice[3] = 2;
  dice[4] = 3;
  dice[5] = 4;
}

void north(int n){
  while(n--){
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[2];
    dice[2] = tmp;
  }
}
void east(int n){
  while(n--){
    int tmp = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[4];
    dice[4] = tmp;
  }
}
void right(int n){
  while(n--){
    int tmp = dice[3];
    dice[3] = dice[4];
    dice[4] = dice[2];
    dice[2] = dice[5];
    dice[5] = tmp;
  }
}

void move(string s){
  if(s[0] == 'N')north(1);
  if(s[0] == 'E')east(1);
  if(s[0] == 'W')east(3);
  if(s[0] == 'S')north(3);
  if(s[0] == 'R')right(1);
  if(s[0] == 'L')right(3);
 

}

int main(){
  int n;
  while(cin >> n && n){
    int sum = 0;
    init();

    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      move(s);
      sum += dice[0];
    }
    cout << sum+1 << endl;
  }
  return 0;
}