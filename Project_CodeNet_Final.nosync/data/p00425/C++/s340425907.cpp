/*
	0502:Dice
*/
#include	<iostream>
#include	<string>

using namespace std;

int main(void) {
	while(1) {
		int n;
		int Top = 1, Front = 2, RigSide = 3, LefSide = 4, Back = 5, Under = 6;
		int sum = 1;
		cin >> n;
		if(n == 0) { break; }
		
		for(int i = 0; i < n; i++) {
			string command;
			cin >> command;
			if(command == "North") {
				int tmp = Top;
				Top = Front;
				Front = Under;
				Under = Back;
				Back = tmp;
			} else if(command == "East") {
				int tmp = Top;
				Top = LefSide;
				LefSide = Under;
				Under = RigSide;
				RigSide = tmp;
			} else if(command == "West") {
				int tmp = Top;
				Top = RigSide;
				RigSide = Under;
				Under = LefSide;
				LefSide = tmp;
			} else if(command == "South") {
				int tmp = Top;
				Top = Back;
				Back = Under;
				Under = Front;
				Front = tmp;
			} else if(command == "Right") {
				int tmp = Front;
				Front = RigSide;
				RigSide = Back;
				Back = LefSide;
				LefSide = tmp;
			} else {
				int tmp = Front;
				Front = LefSide;
				LefSide = Back;
				Back = RigSide;
				RigSide = tmp;
			}
			sum += Top;
		}
		cout << sum << endl;
	}
	
	return 0;
}