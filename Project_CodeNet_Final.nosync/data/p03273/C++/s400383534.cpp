#include <iostream>

using namespace std;

int h, w;
char c[105][105];
bool delx[105], dely[105];

int main(void)
{
	cin >> h >> w;
	for(int y = 1; y <= h; y++){
		for(int x = 1; x <= w; x++){
			cin >> c[x][y];
		}
	}
	
	for(int y = 1; y <= h; y++){
		bool flag = false;
		for(int x = 1; x <= w; x++){
			if(c[x][y] == '#'){
				flag = true;
				break;
			}
		}
		if(!flag) dely[y] = true;
	}
	
	for(int x = 1; x <= w; x++){
		bool flag = false;
		for(int y = 1; y <= h; y++){
			if(c[x][y] == '#'){
				flag = true;
				break;
			}
		}
		if(!flag) delx[x] = true;
	}
	
	for(int y = 1; y <= h; y++){
		if(dely[y]) continue;
		for(int x = 1; x <= w; x++){
			if(delx[x]) continue;
			cout << c[x][y];
		}
		cout << endl;
	}
	
	return 0;
}