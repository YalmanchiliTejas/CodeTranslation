#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int dice[6] ={1, 3, 2, 6, 4, 5};
int sub[6];
int total = 0;

char East[] = "East";
char West[] = "West";
char North[]= "North";
char South[]= "South";
char Right[]= "Right";
char Left[] = "Left";

void copy_arr(void){
	for(int i = 0; i < 6; i++){
		sub[i] = dice[i];
	}
}

void change_dice(char s[]){
	if(strcmp(East,s) == 0){
		copy_arr();
		dice[0] = sub[4];		
		dice[1] = sub[0];
		dice[3] = sub[1];
		dice[4] = sub[3];
	}
	else if(strcmp(West,s) == 0){
		copy_arr();
		dice[0] = sub[1];		
		dice[1] = sub[3];
		dice[3] = sub[4];
		dice[4] = sub[0];
	}
	else if(strcmp(North,s) == 0){
		copy_arr();
		dice[0] = sub[2];		
		dice[2] = sub[3];
		dice[3] = sub[5];
		dice[5] = sub[0];
	}
	else if(strcmp(South,s) == 0){
		copy_arr();
		dice[0] = sub[5];		
		dice[2] = sub[0];
		dice[3] = sub[2];
		dice[5] = sub[3];
	}
	else if(strcmp(Right,s) == 0){
		copy_arr();
		dice[1] = sub[5];
		dice[2] = sub[1];
		dice[4] = sub[2];
		dice[5] = sub[4];
	}
	else if(strcmp(Left,s) == 0){
		copy_arr();
		dice[1] = sub[2];
		dice[2] = sub[4];
		dice[4] = sub[5];
		dice[5] = sub[1];
	}
	else{
		cout << "ERR" << endl;
	}
	total += dice[0];
}

int main()
{
	int n;
	for(;;){
		total = 0;
		char s[10000][6] = {0};
		dice[0] = 1;
		dice[1] = 3;
		dice[2] = 2;
		dice[3] = 6;
		dice[4] = 4;
		dice[5] = 5;
		
		cin >> n;
		if(n == 0){
			break;
		}
		
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		
		for(int i = 0; i < n; i++){
			change_dice(s[i]);
		}
		cout << total+1 << endl;
	}
}