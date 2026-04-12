#include<iostream>

using namespace std;

int data[6];
int next[6];
int sum;

void init(){
  data[0] = 4;
  data[1] = 1;
  data[2] = 3;
  data[3] = 6;
  data[4] = 2;
  data[5] = 5;
  sum = 1;
}

void copy(){
  for(int i = 0; i < 6; i++) next[i] = data[i];
}

void N(int num){
  for(int i = 0; i < num; i++){
    copy();
    data[1] = next[4];
    data[3] = next[5];
    data[4] = next[3];
    data[5] = next[1];
  }
}

void W(int num){
  for(int i = 0; i < num; i++){
    copy();
    data[0] = next[1];
    data[1] = next[2];
    data[2] = next[3];
    data[3] = next[0];
  }
}

void R(int num){
  for(int i = 0; i < num; i++){
    copy();
    data[0] = next[4];
    data[2] = next[5];
    data[4] = next[2];
    data[5] = next[0];
  }
}

void move(string in){
  if(in == "North") N(1);
  if(in == "South") N(3);
  if(in == "West") W(1);
  if(in == "East") W(3);
  if(in == "Right") R(1);
  if(in == "Left") R(3);
}

int main(){

  int in;
  while(cin >> in && in){
    init();
    for(int i = 0; i < in; i++){
      string str;
      cin >> str;
      move(str);
      sum += data[1];
    }
    cout << sum << endl;
  }
  return 0;
}