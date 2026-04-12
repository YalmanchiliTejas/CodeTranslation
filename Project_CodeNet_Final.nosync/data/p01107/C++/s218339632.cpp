#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


enum DIR{
	North,
	East,
	South,
	West,
};

struct Info{
	bool left_wall,under_wall;
};

struct Data{
	void  set(int arg_x,int arg_y){
		x = arg_x;
		y = arg_y;
	}
	int x,y;
};

struct State{
	void set(int arg_x,int arg_y,DIR arg_dir){
		x = arg_x;
		y = arg_y;
		dir = arg_dir;
	}
	int x,y;
	DIR dir;
};

int H,W;
Info info[51][51];
Data start[4],goal[4],FROM,TO;
char base_map[50][51];
bool visited[51][51][4];


void func(){

	for(int y = H-1; y >= 0; y--){
		scanf("%s",base_map[y]);
	}

	for(int x = 0; x <= W; x++){
		for(int y = 0; y <= H; y++){
			info[x][y].left_wall = false;
			info[x][y].under_wall = false;

			for(int i = 0; i < 4; i++)visited[x][y][i] = false;

		}
	}

	for(int y = 0; y < H; y++){
		info[0][y].left_wall = true;
	}

	for(int x = 0; x < W; x++){
		info[x][H].under_wall = true;
	}

	for(int y = 0; y < H; y++){
		info[W][y].left_wall = true;
	}

	for(int x = 0; x < W; x++){
		info[x][0].under_wall = true;
	}

	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){
			if(base_map[y][x] == '#'){
				info[x][y].left_wall = true;
				info[x][y].under_wall = true;
				info[x+1][y].left_wall = true;
				info[x][y+1].under_wall = true;
			}
		}
	}

	start[0].set(0,H-1);
	start[1].set(W-1,H-1);
	start[2].set(W-1,0);
	start[3].set(0,0);

	goal[0].set(W-1,H-1);
	goal[1].set(W-1,0);
	goal[2].set(0,0);
	goal[3].set(0,H-1);


	State state;
	bool Cleard,Check,FLG;

	for(int loop = 0; loop < 4; loop++){

		FROM = start[loop];
		TO = goal[loop];

		switch(loop){
		case 0:
			state.set(FROM.x,FROM.y,East);
			break;
		case 1:
			state.set(FROM.x,FROM.y,South);
			break;
		case 2:
			state.set(FROM.x,FROM.y,West);
			break;
		case 3:
			state.set(FROM.x,FROM.y,North);
			break;
		}

		for(int i = 0; i < 4; i++){
			visited[0][H-1][i] = false;
		}

		Cleard = false;

		while(true){

			FLG = true;

			switch(state.dir){
			case North:
				if(info[state.x][state.y].left_wall == false){
					FLG = false;
				}
				break;
			case East:
				if(info[state.x][state.y+1].under_wall == false){
					FLG = false;
				}
				break;
			case South:
				if(info[state.x+1][state.y].left_wall == false){
					FLG = false;
				}
				break;
			case West:
				if(info[state.x][state.y].under_wall == false){
					FLG = false;
				}
				break;
			}

			if(FLG){

				switch(state.dir){
				case North:
					if(info[state.x][state.y+1].under_wall == false){
						state.y++;
					}else{
						state.dir = East;
					}
					break;
				case East:
					if(info[state.x+1][state.y].left_wall == false){
						state.x++;
					}else{
						state.dir = South;
					}
					break;
				case South:
					if(info[state.x][state.y].under_wall == false){
						state.y--;
					}else{
						state.dir = West;
					}
					break;
				case West:
					if(info[state.x][state.y].left_wall == false){
						state.x--;
					}else{
						state.dir = North;
					}
					break;
				}

			}else{

				switch(state.dir){
				case North:
					if(state.x-1 == TO.x && state.y == TO.y){
						Cleard = true;
					}else{

						state.x--;

						if(info[state.x][state.y].under_wall == true){
							state.dir = West;
						}else{
							state.y--;
							state.dir = South;
						}
					}
					break;
				case East:
					if(state.x == TO.x && state.y+1 == TO.y){
						Cleard = true;
					}else{
						state.y++;

						if(info[state.x][state.y].left_wall == true){
							state.dir = North;
						}else{
							state.x--;
							state.dir = West;
						}
					}
					break;
				case South:
					if(state.x+1 == TO.x && state.y == TO.y){
						Cleard = true;
					}else{
						state.x++;

						if(info[state.x][state.y+1].under_wall == true){
							state.dir = East;
						}else{
							state.y++;
							state.dir = North;
						}
					}
					break;
				case West:
					if(state.x == TO.x && state.y-1 == TO.y){
						Cleard = true;
					}else{
						state.y--;

						if(info[state.x+1][state.y].left_wall == true){
							state.dir = South;
						}else{
							state.x++;
							state.dir = East;
						}
					}
					break;
				}

				if(Cleard)break;
			}

			if(visited[state.x][state.y][state.dir]){
				break;
			}
			visited[state.x][state.y][state.dir] = true;

			if(state.x == TO.x && state.y == TO.y){
				Cleard = true;
				break;
			}
		}

		if(!Cleard){
			break;
		}else{

			if(loop == 3)break;

			for(int x = 0; x < W; x++){
				for(int y = 0; y < H; y++){

					Check = false;

					if((x == 0 && y == H-1)||(x == TO.x && y == TO.y))continue;

					for(int i = 0; i < 4; i++){
						if(visited[x][y][i]){
							Check = true;
							break;
						}
					}


					if(Check){
						for(int i = 0; i < 4;i++)visited[x][y][i] = true;
					}
				}
			}
		}
	}

	if(Cleard){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}


int main(){

	while(true){
		scanf("%d %d",&H,&W);
		if(H == 0 && W == 0)break;

		func();
	}

	return 0;
}


