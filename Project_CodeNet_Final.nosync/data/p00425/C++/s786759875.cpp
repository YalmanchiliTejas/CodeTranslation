#include <iostream>
#include <cstring>
using namespace std;

void rotate(int& a, int&b, int&c, int&d){
  int aa = a;
  int bb = b;
  int cc = c;
  int dd = d;
  a = dd;
  b = aa;
  c = bb;
  d = cc;
};

int main(){
  char op[8];
  int num;
  int dice[6];
  int temp[4];
  int sum;

  while(cin >> num && num){
    dice[0] = 1;
    dice[1] = 6;
    dice[2] = 5;
    dice[3] = 3;
    dice[4] = 2;
    dice[5] = 4;
    sum = 1;
  for(; num; num--){
    cin >> op;
    if(!strcmp(op, "North")) rotate(dice[0], dice[2], dice[1], dice[4]);
    else if(!strcmp(op, "East")) rotate(dice[0], dice[3], dice[1], dice[5]);
    else if(!strcmp(op, "South")) rotate(dice[0], dice[4], dice[1], dice[2]);
    else if(!strcmp(op, "West")) rotate(dice[0], dice[5], dice[1], dice[3]);
    else if(!strcmp(op, "Right")) rotate(dice[2], dice[3], dice[4], dice[5]);
    else if(!strcmp(op, "Left")) rotate(dice[5], dice[4], dice[3], dice[2]);
    sum += dice[0];
  }
  cout << sum << "\n";
}

return 0;
}