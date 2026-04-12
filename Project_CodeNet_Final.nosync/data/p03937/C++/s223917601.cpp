#include<iostream>
#include<algorithm>

using namespace std;

int h, w, sum_hash = 0;
char mass[9][9];

int move(int x, int y, int hash){

	if(hash == sum_hash && x == h -1 && y == w -1)
		return 1;
	if(mass[x + 1][y] != '#'  && mass[x][y + 1] != '#')
		return 0;

	return max(move(x + 1, y, hash + 1),move(x, y + 1, hash + 1)); 

}

int main(){
	
	cin >> h >> w;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++){
			cin >> mass[i][j];
			if(mass[i][j] == '#')
				sum_hash++;
		}

	
	if(move(0, 0, 1)){
		cout << "Possible" <<endl;
		return 0;
	}

	cout << "Impossible" << endl;

	return 0;
}
