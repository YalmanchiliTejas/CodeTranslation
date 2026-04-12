#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int dice[6] = {1, 5, 3, 2, 4, 6};

void init() {
	dice[0] = 1;
	dice[1] = 5;
	dice[2] = 3;
	dice[3] = 2;
	dice[4] = 4;
	dice[5] = 6;
}

void rright() {
	int north = dice[1];
	int east = dice[2];
	int south = dice[3];
	int west = dice[4];
	dice[1] = west;
	dice[2] = north;
	dice[3] = east;
	dice[4] = south;
}

void rleft() {
	rright();
	rright();
	rright();
}

void rnorth() {
	int top = dice[0];
	int north = dice[1];
	int south = dice[3];
	int floor = dice[5];
	dice[0] = south;
	dice[1] = top;
	dice[3] = floor;
	dice[5] = north;
}

void rsouth() {
	rnorth();
	rnorth();
	rnorth();
}

void reast() {
	int top = dice[0];
	int east = dice[2];
	int floor = dice[5];
	int west = dice[4];
	dice[0] = west;
	dice[2] = top;
	dice[5] = east;
	dice[4] = floor;
}

void rwest() {
	reast();
	reast();
	reast();
}

int main() {
	while(1) {
	  int n;
	  cin >> n;
	  if(n == 0) break;
	  init();
	  int sum = 1;
	  rep(i, n) {
		  string s;
		  cin >> s;
		  if(s == "North") rnorth();
		  else if(s == "East") reast();
		  else if(s == "West") rwest();
		  else if(s == "South") rsouth();
		  else if(s == "Right") rright();
		  else if(s == "Left") rleft();
		  else cout << "Error!" << endl;
		  sum += dice[0];
	  }
	  cout << sum << endl;
	}
	return 0;
}