#include <iostream>

using namespace std;

int H, W;
char map[8][8];
char used[8][8];

int main(void)
{
	cin >> H >> W;
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){
			cin >> map[x][y];
		}
	}
	
	int cx = 0, cy = 0;
	while(1){
		used[cx][cy] = true;
		if(cx < W-1 && map[cx+1][cy] == '#') cx++;
		else if(cy < H-1 && map[cx][cy+1] == '#') cy++;
		else break;
	}
	
	for(int x = 0; x < W; x++){
		for(int y = 0; y < H; y++){
			if(map[x][y] == '#' && !used[x][y]){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	return 0;
}