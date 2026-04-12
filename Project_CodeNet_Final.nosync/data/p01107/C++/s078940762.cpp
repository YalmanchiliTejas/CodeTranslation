#include <iostream>

using namespace std;

int H, W;
char map[55][55];
int used[55][55];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

int main(void)
{
	while(1){
		cin >> H >> W;
		if(H == 0 && W == 0) break;
		for(int y = 1; y <= H; y++){
			for(int x = 1; x <= W; x++){
				cin >> map[x][y];
			}
		}
		if(map[1][1] == '#' || map[1][H] == '#' || map[W][H] == '#' || map[W][1] == '#'){
			cout << "NO" << endl;
			continue;
		}
		if(map[1][2] = '#' && map[2][1] == '#'){
			cout << "NO" << endl;
			continue;
		}
		map[1][1] = '4';
		map[1][H] = '1';
		map[W][H] = '2';
		map[W][1] = '3';
		
		for(int x = 1; x <= W; x++){
			for(int y = 1; y <= H; y++){
				used[x][y] = 0;
			}
		}
		
		int x = 1, y = 1, dir = 3;
		for(int i = 1; i <= 4; i++){
			while(1){
				for(dir = (dir+3)%4; ; dir = (dir+1)%4){
					int nx = x + dx[dir], ny = y + dy[dir];
					if(nx < 1 || nx > W || ny < 1 || ny > H) continue;
					if(map[nx][ny] != '#') break;
				}
				x += dx[dir], y += dy[dir];
				if(map[x][y] >= '1' && map[x][y] <= '4'){
					if(map[x][y] != i + '0'){
						cout << "NO" << endl;
						goto end;
					}
					break;
				}
				if(used[x][y] != 0 && used[x][y] != i){
					cout << "NO" << endl;
					goto end;
				}
				used[x][y] = i;
			}
		}
		cout << "YES" << endl;
		end:;
	}
	
	return 0;
}
