#include <iostream>
#include <string>

using namespace std;
void rot(int *dice, int a, int b, int c, int d){
	int tmp = dice[a];
	dice[a] = dice[b];
	dice[b] = dice[c];
	dice[c] = dice[d];
	dice[d] = tmp;
}

int main(){
	int n;
	while (cin >> n, n){
		int dice[6] = { 1, 2, 3, 4, 5, 6 }, ans = 1;
		for (int i = 0; i < n; i++){
			string command;
			cin >> command;
			if (command == "North"){
				rot(dice, 0, 1, 5, 4);
			} else if (command == "East"){
				rot(dice, 0, 3, 5, 2);
			} else if (command == "West"){
				rot(dice, 2, 5, 3, 0);
			} else if (command == "South"){
				rot(dice, 4, 5, 1, 0);
			} else if (command == "Right"){
				rot(dice, 2, 4, 3, 1);
			} else /* Left */{
				rot(dice, 1, 3, 4, 2);
			}
			ans += dice[0];
		}
		cout << ans << endl;
	}
}