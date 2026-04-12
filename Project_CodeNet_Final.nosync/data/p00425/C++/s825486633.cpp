#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Dice{
public:
  int u,d,n,s,e,w;
  Dice(){
    u = 1;
    d = 6;
    s = 2;
    n = 5;
    e = 3;
    w = 4;
  }
  void cir(int & a , int & b , int & c , int & d){
    int t = a;
    a = b;
    b = c;
    c = d;
    d = t;
  }
  void rot(string com){
    if(com == "North"){
      cir(u , s , d , n);
    } else if(com == "South"){
      cir(u , n , d , s);
    } else if(com == "East"){
      cir(u , w , d , e);
    } else if(com == "West"){
      cir(u , e , d , w);
    } else if(com == "Right"){
      cir(s , e , n , w);
    } else if(com == "Left"){
      cir(s , w , n , e);
    }
  }
};

int main(void){
  int n;
  while(cin >> n , n){
    int sum = 1;
    Dice D;
    for(int i = 0; i < n; i++){
      string com;
      cin >> com;
      D.rot(com);
      sum += D.u;
    }
    cout << sum << endl;
  }
  return 0;
}