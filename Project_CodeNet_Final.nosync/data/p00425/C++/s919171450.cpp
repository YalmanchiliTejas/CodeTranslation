#include<iostream>
using namespace std;
int main(void){
	int a;
	char di[100];
	cin >> a;
	while (a != 0){
		int  d, g = 1, i, dice[6] = {1, 2, 3, 4, 5, 6};
		for (i = 0; i < a; i++){
			cin >> di;
			if (di[0] == 'N'){
				d = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = d;
			}
			if (di[0] == 'E'){
				d = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = d;
			}
			if (di[0] == 'W'){
				d = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = d;
			}
			if (di[0] == 'S'){
				d = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = d;
			}
			if (di[0] == 'R'){
				d = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[3];
				dice[3] = d;
			}
			if (di[0] == 'L'){
				d = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];
				dice[4] = dice[2];
				dice[2] = d;
			}
			g = g + dice[0];
		}
		cout << g << endl;
		cin >> a;
	}
}