#include<iostream>

using namespace std;

class Dice{

public:
  int top,bottom,north,south,west,east;

  Dice(){}
  Dice(int t, int b, int n, int s, int w, int e)
    :top(t),bottom(b),north(n),south(s),west(w),east(e){}

  void setDice(int t, int b, int n, int s, int w, int e){
    top = t; bottom = b, north = n; south = s, west = w; east = e;
  }

  void rotateNorth(){setDice(south,north,top,bottom,west,east);}
  void rotateSouth(){setDice(north,south,bottom,top,west,east);}
  void rotateEast(){setDice(west,east,north,south,bottom,top);}
  void rotateWest(){setDice(east,west,north,south,top,bottom);}
  void rotateCW(){setDice(top,bottom,west,east,south,north);}
  void rotateCCW(){setDice(top,bottom,east,west,north,south);}
};


int main(){

  int n;
  while(cin >> n && n){
    Dice d(1,6,5,2,4,3);
    int sum = 0;
    while(n--){
      string s;
      cin >> s;
      if(s[0] == 'N') d.rotateNorth();
      if(s[0] == 'S') d.rotateSouth();
      if(s[0] == 'E') d.rotateEast();
      if(s[0] == 'W') d.rotateWest();
      if(s[0] == 'R') d.rotateCW();
      if(s[0] == 'L') d.rotateCCW();
      //cout << d.top << endl;
      sum += d.top;
    }
    cout << sum+1 << endl;
  }
  return 0;
}