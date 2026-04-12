#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

void rotate(int dice[], string mode){
	int dice_c[6];
	for (int i = 0; i < 6; i++) dice_c[i] = dice[i];
	if (mode == "North"){
		dice[0] = dice_c[1];
		dice[1] = dice_c[5];
		dice[2] = dice_c[2];
		dice[3] = dice_c[3];
		dice[4] = dice_c[0];
		dice[5] = dice_c[4];
	}
	else if (mode == "East"){
		dice[0] = dice_c[3];
		dice[1] = dice_c[1];
		dice[2] = dice_c[0];
		dice[3] = dice_c[5];
		dice[4] = dice_c[4];
		dice[5] = dice_c[2];
	}
	else if (mode == "West"){
		dice[0] = dice_c[2];
		dice[1] = dice_c[1];
		dice[2] = dice_c[5];
		dice[3] = dice_c[0];
		dice[4] = dice_c[4];
		dice[5] = dice_c[3];
	}
	else if (mode == "South"){
		dice[0] = dice_c[4];
		dice[1] = dice_c[0];
		dice[2] = dice_c[2];
		dice[3] = dice_c[3];
		dice[4] = dice_c[5];
		dice[5] = dice_c[1];
	}
	else if (mode == "Right"){
		dice[0] = dice_c[0];
		dice[1] = dice_c[2];
		dice[2] = dice_c[4];
		dice[3] = dice_c[1];
		dice[4] = dice_c[3];
		dice[5] = dice_c[5];
	}
	else if (mode == "Left"){
		dice[0] = dice_c[0];
		dice[1] = dice_c[3];
		dice[2] = dice_c[1];
		dice[3] = dice_c[4];
		dice[4] = dice_c[2];
		dice[5] = dice_c[5];
	}
}

int main(){
	int n;
	string input;
	while (cin >> n, n){
		int dice[6] = { 1, 2, 3, 4, 5, 6 }, ans = 1;
		for (int i = 0; i < n; i++){
			cin >> input;
			rotate(dice, input);
			ans += dice[0];
		}
		printf("%d\n", ans);
	}
}