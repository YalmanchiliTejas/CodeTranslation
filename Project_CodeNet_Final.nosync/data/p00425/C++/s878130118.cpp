#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define TOP 0 
#define BOTTOM 1
#define FRONT 2
#define BACK 3
#define RIGHT 4
#define LEFT 5

void north(int dice[]){
	int to[6];
	to[BACK] = dice[TOP];
	to[BOTTOM] = dice[BACK];
	to[FRONT] = dice[BOTTOM];
	to[TOP] = dice[FRONT];

	to[LEFT] = dice[LEFT];
	to[RIGHT] = dice[RIGHT];

	rep(i,6)dice[i] = to[i];

}

void right(int dice[]){
	int to[6];
	to[FRONT] = dice[LEFT];
	to[LEFT] = dice[BACK];
	to[BACK] = dice[RIGHT];
	to[RIGHT] = dice[FRONT];
	
	to[BOTTOM] = dice[BOTTOM];
	to[TOP] = dice[TOP];
	
	rep(i,6)dice[i] = to[i];
}

void east(int dice[]){
	int to[6];
	to[TOP] = dice[LEFT];
	to[LEFT] = dice[BOTTOM];
	to[BOTTOM] = dice[RIGHT];
	to[RIGHT] = dice[TOP];
	
	to[FRONT] = dice[FRONT];
	to[BACK] = dice[BACK];
	
	rep(i,6)dice[i] = to[i];
}


int main(){
	string s;
	int n;
	
	while(cin >> n ,n){
		int ret = 1;
		int dice[6] = {1,6,2,5,3,4};
		
		rep(i,n){
			cin >> s;
			switch(s[0]){
			case 'N':
				north(dice);
				break;
			case 'S':
				rep(i,3)north(dice);
				break;
			case 'R':
				rep(i,3)right(dice);
				break;
			case 'L':
				right(dice);
				break;
			case 'E':
				east(dice);
				break;
			case 'W':
				rep(i,3)east(dice);
				break;
			}
			ret += dice[0];
		}
		cout << ret << endl;
	}
}