#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstring>

using namespace std;

struct mountain{
  char stack[1001];
  int sp;
};

int main(){

  int n,p1,p2;
  char c,cmd[5];

  cin >> n;
  mountain mnt[n];

  for(int i = 0; i < n; i++){
    mnt[i].sp = 0;
  }

  while(1){
    cin >> cmd;
    if(!strcmp(cmd, "push")){
      cin >> p1 >> c;
      mnt[p1-1].stack[mnt[p1-1].sp] = c;
      mnt[p1-1].sp++;
    }
    if(!strcmp(cmd, "pop")){
      cin >> p1;
      cout << mnt[p1-1].stack[mnt[p1-1].sp-1] << endl;
      mnt[p1-1].sp--;
    }
    if(!strcmp(cmd, "move")){
      cin >> p1 >> p2;
      mnt[p2-1].stack[mnt[p2-1].sp] = mnt[p1-1].stack[mnt[p1-1].sp-1];
      mnt[p1-1].sp--;
      mnt[p2-1].sp++;
    }
    if(!strcmp(cmd, "quit")){
      break;
    }
  }

  return 0;
}