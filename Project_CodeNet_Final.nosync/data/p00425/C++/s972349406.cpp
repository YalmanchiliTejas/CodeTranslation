#include <iostream>
using namespace std;

int dicebottom(int top) {
  return 7 - top;
}

int dicedown(int up) {
  return 7 - up;
}

int diceright(int left) {
  return 7 - left;
}


int main() {
  int top, up, left, bottom, down, right;
  int n,sum,hold;
  string order;
  while(cin >> n) {
    if(n == 0) break;
    top = 1;
    up = 5;
    left = 4;
    bottom = 6;
    down = 2;
    right = 3;
    //dice(top,up,left,bottom,down,right);
    sum = 1;

    for(int i=0;i<n;i++) {
      cin >> order;
      if(order == "North") {
	hold = top;
	top = down;
	up = hold;
      }
      else if(order == "East") {
	top = left;
	left = bottom;
      }
      else if(order == "West") {
	hold = top;
	top = right;
	left = hold;
      }
      else if(order == "South") {
	top = up;
	up = bottom;
      }
      else if(order == "Right") {
	up = left;
	left = down;
      }
      else if(order == "Left") {
	hold = up;
	up = right;
	left = hold;
      }
      bottom = dicebottom(top);
      down = dicedown(up);
      right = diceright(left);
      //cout << top << " " << up << " " << left << " " << bottom << " " << down << " " << right << endl;
      sum += top;
    }
    cout << sum << endl;
  }
}