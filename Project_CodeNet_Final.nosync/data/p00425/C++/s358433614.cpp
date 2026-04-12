#include<iostream>

using namespace std;

int map[4];
int now, out;

void changeMap(string direction) {
	int tmp;
	if(direction == "North") {
		tmp = out;
		out = map[3];
		map[3] = now;
		now = map[0];
		map[0] = tmp;
	} else if(direction == "East") {
		tmp = out;
		out = map[2];
		map[2] = now;
		now = map[1];
		map[1] = tmp;
	} else if(direction == "West") {
		tmp = out;
		out = map[1];
		map[1] = now;
		now = map[2];
		map[2] = tmp;
	} else if(direction == "South") {
		tmp = out;
		out = map[0];
		map[0] = now;
		now = map[3];
		map[3] = tmp;
	} else if(direction == "Right") {
		tmp = map[0];
		map[0] = map[2];
		map[2] = map[3];
		map[3] = map[1];
		map[1] = tmp;
	} else if(direction == "Left") {
		tmp = map[0];
		map[0] = map[1];
		map[1] = map[3];
		map[3] = map[2];
		map[2] = tmp;
	}
}

int main(void) {
	int num, count;
	string in;
	int i;

	while(true) {
		cin >> num;
		if(num == 0) { break; }
		map[0] = 2; map[1] = 4; map[2] = 3; map[3] = 5;
		now = 1; out = 6;
		count = now;
		for(i = 0; i < num; i++) {
			cin >> in;
			changeMap(in);
			count += now;
		}
		cout << count << endl;
	}

	return 0;
}