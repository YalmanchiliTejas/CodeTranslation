#include <iostream>
using namespace std;

class Dice{
public:
  int t, s, e, n, w, b;
  Dice(){}
  Dice(int t, int s, int e, int n, int w, int b) :
    t(t), s(s), e(e), n(n), w(w), b(b) {}
  Dice moveEast()  { return Dice(w, s, t, n, b, e); }
  Dice moveNorth() { return Dice(s, b, e, t, w, n); }
  Dice moveRight() { return Dice(t, e, n, w, s, b); }
};

int main(){
  int n;

  while(cin >> n, n){
    Dice d(1, 2, 3, 5, 4, 6);
    int sum = 1;

    for(int i = 0; i < n; i++){
      string s;
      cin >> s;

      if(s == "North")      d = d.moveNorth();
      else if(s == "East")  d = d.moveEast();
      else if(s == "South") d = d.moveNorth().moveNorth().moveNorth();
      else if(s == "West")  d = d.moveEast().moveEast().moveEast();
      else if(s == "Right") d = d.moveRight();
      else                  d = d.moveRight().moveRight().moveRight();

      sum += d.t;
    }

    cout << sum << endl;
  }
}