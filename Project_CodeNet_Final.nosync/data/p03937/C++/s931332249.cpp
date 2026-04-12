#include<iostream>
using namespace std;
char X[8][9];
int H,W;

int main(){
	cin >> H >> W;
	for(int i=0; i<H; i++){
		cin >> X[i];
	}

	int x=0, y=0;
	while(x<H-1 || y<W-1){
		//cout << x << " " << y << endl;
		//cout << X[x+1][y] << " " << X[x][y+1] << endl;
		if(x>0 && y>0 && X[x-1][y] == X[x][y-1]){
			cout << "Impossible" << endl;
			return 0;
		}
		if(x == H-1){
			if(X[x][y+1] == '.'){
				cout << "Impossible" << endl;
				return 0;
			}
			else{
				y++;
				continue;
			}
		}
		if(y == W-1){
			if(X[x+1][y] == '.'){
				cout << "Impossible" << endl;
				return 0;
			}
			else{
				x++;
				continue;
			}
		}
		if(X[x+1][y] == X[x][y+1]){
			cout << "Impossible" << endl;
			return 0;
		}
		if(X[x+1][y] == '#') x++;
		else y++;
	}
	if(X[x-1][y] == X[x][y-1]){
		cout << "Impossible" << endl;
		return 0;
	}

	cout << "Possible" << endl;
	return 0;
}
