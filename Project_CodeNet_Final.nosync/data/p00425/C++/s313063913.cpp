#include <iostream>
#include <cstdio>
using namespace std;

struct Dice{
  int id[6];
  /*index number:
    0:top, 1:front, 2:right, 3:left, 4:back, 5:bottom 
  */
  Dice(){
    id[0] = 1, id[1] = 2, id[2] = 3, id[3] = 5, id[4] = 4, id[5] = 6;
  }
  Dice(int a, int b, int c, int d, int e, int f){
    id[0] = a, id[1] = b, id[2] = c, id[3] = d, id[4] = e, id[5] = f;
  }
  void north(){
    int d[6];
    for(int i=0;i<6;i++) d[i]=id[i];
    id[0]=d[1];
    id[1]=d[5];
    id[2]=d[2];
    id[3]=d[0];
    id[4]=d[4];
    id[5]=d[3];
  }
  
  void south(){
    int d[6];
    for(int i=0;i<6;i++) d[i]=id[i];
    id[0]=d[3];
    id[1]=d[0];
    id[2]=d[2];
    id[3]=d[5];
    id[4]=d[4];
    id[5]=d[1];
  }
  
  void east(){
    int d[6];
    for(int i=0;i<6;i++) d[i]=id[i];
    id[0]=d[4];
    id[1]=d[1];
    id[2]=d[0];
    id[3]=d[3];
    id[4]=d[5];
    id[5]=d[2];
  }
  
  void west(){
    int d[6];
    for(int i=0;i<6;i++) d[i]=id[i];
    id[0]=d[2];
    id[1]=d[1];
    id[2]=d[5];
    id[3]=d[3];
    id[4]=d[0];
    id[5]=d[4];
  }
  
  void right(){
    int d[6];
    for(int i=0;i<6;i++) d[i]=id[i];
    id[0]=d[0];
    id[1]=d[2];
    id[2]=d[3];
    id[3]=d[4];
    id[4]=d[1];
    id[5]=d[5];
  }
  
  void left(){
    int d[6];
    for(int i=0;i<6;i++) d[i]=id[i];
    id[0]=d[0];
    id[1]=d[4];
    id[2]=d[1];
    id[3]=d[2];
    id[4]=d[3];
    id[5]=d[5];
  }
};

int main(){
  int n;
  while(cin >> n, n){
    Dice dice;
    string s;
    int ans = 1;
    for(int i = 0 ; i < n ; i++){
      cin >> s;
      if(s == "North") dice.north();
      if(s == "East") dice.east();
      if(s == "South") dice.south();
      if(s == "West") dice.west();
      if(s == "Left") dice.left();
      if(s == "Right") dice.right();
      ans += dice.id[0];
    }
    cout << ans << endl;
  }
  return 0;
}