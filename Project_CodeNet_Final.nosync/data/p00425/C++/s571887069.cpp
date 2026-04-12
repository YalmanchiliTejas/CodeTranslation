#include <iostream>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;


int n, s;
int north, east, south, west, top, bottom, temp;
string dir;

int main(void) {
  while(1) {
    cin >> n;
    if(n == 0) break;

    s = 1;
    top = 1; south = 2; east = 3; west = 4; north = 5; bottom = 6;

    REP(i, 0, n) {
      cin >> dir;
      if(dir == "North") { temp = bottom; bottom = north; north = top; top = south; south = temp; }
      if(dir == "East")  { temp = bottom; bottom = east; east = top; top = west; west = temp; }
      if(dir == "South") { temp = bottom; bottom = south; south = top; top = north; north = temp; }
      if(dir == "West")  { temp = bottom; bottom = west; west = top; top = east; east = temp; }
      if(dir == "Right") { temp = north; north = west; west = south; south = east; east = temp; }
      if(dir == "Left")  { temp = north; north = east; east = south; south = west; west = temp; }
      s += top;
    }

    cout << s << endl;
  }

  return 0;
}