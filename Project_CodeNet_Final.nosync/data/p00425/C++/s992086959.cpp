#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Dice{
public:
  int c[3];

  Dice(){
    for(int i = 0 ; i < 3 ; i++)c[i] = i+1;
  }

  int getTop(){
    return c[0];
  }

  void rN(){
    swap(c[0],c[1]);
    c[1] = 7 - c[1];
  }
  
  void rE(){
    swap(c[0],c[2]);
    c[0] = 7 - c[0];
  }
  
  void rW(){
    swap(c[0],c[2]);
    c[2] = 7 - c[2];
  }
  
  void rS(){
    swap(c[0],c[1]);
    c[0] = 7 - c[0];
  }

  void rR(){
    swap(c[1],c[2]);
    c[2] = 7 - c[2];
  }

  void rL(){
    swap(c[1],c[2]);
    c[1] = 7 - c[1];
  }
};

int N;

void solve(){
  string str;
  int res = 1;
  Dice dice;

  for(int i = 0 ; i < N ; i++){
    cin >> str;
    switch(str[0]){
    case 'N':
      dice.rN();
      break;
    case 'E':
      dice.rE();
      break;
    case 'W':
      dice.rW();
      break;
    case 'S':
      dice.rS();
      break;
    case 'R':
      dice.rR();
      break;
    case 'L':
      dice.rL();
      break;
    }
    res += dice.getTop();
  }
  cout << res  << endl;
}

int main(){
  while(cin >> N,N)solve();
  return 0;
}