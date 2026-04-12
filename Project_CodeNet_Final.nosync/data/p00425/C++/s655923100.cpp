#include <iostream>
using namespace std;
class Dice {
private:
  int dice[6];
 public:
  Dice() {
	for(int i = 0; i < 6; ++i) {
	  dice[i] = i + 1;
	}
  }
  void move(string str) {
	if(str == "North") {
	  rollN();
	}
	else if(str == "South") {
	  rollS();
	}
	else if(str == "East") {
	  rollE();
	}
	else if(str == "West") {
	  rollW();
	}
	else if(str == "Left") {
	  spinL();
	}
	else {	// Right
	  spinR();
	}
  }
  void rollN() {
	swap(dice[0], dice[1]);
	swap(dice[1], dice[5]);
	swap(dice[5], dice[4]);
  }
  void rollS() {
	swap(dice[0], dice[4]);
	swap(dice[4], dice[5]);
	swap(dice[5], dice[1]);
  }
  void rollE() {
	swap(dice[0], dice[3]);
	swap(dice[3], dice[5]);
	swap(dice[5], dice[2]);
  }
  void rollW() {
	swap(dice[0], dice[2]);
	swap(dice[2], dice[5]);
	swap(dice[5], dice[3]);
  }
  void spinL() {
	swap(dice[3], dice[4]);
	swap(dice[4], dice[2]);
	swap(dice[2], dice[1]);
  }
  void spinR() {
	swap(dice[1], dice[2]);
	swap(dice[2], dice[4]);
	swap(dice[4], dice[3]);
  }
  int top() {
	return dice[0];
  }
};

int main() {
  int n, sum;
  string str;
  while(cin >> n, n) {
	Dice d1;
	sum = 1;
	for(int i = 0; i < n; ++i) {
	  cin >> str;
	  d1.move(str);
	  sum += d1.top();
	}
	cout << sum << endl;
  }
  return 0;
}