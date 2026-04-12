#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main(void) {
	int h,w;
	cin >> h >> w;
	char grid[10][10];
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> grid[i][j];
		}
	}
	int i=0,j=0;
	while(i<h && j<w){
		int a=0,b=0;
		if(i+1<h && grid[i+1][j]=='#')a=1;
		if(j+1<w && grid[i][j+1]=='#')b=1;
		if((a==1 && b==0)||(a==0 &&b==1)){
			i+=a;
			j+=b;
		}else {
			cout << "Impossible" << endl;
			return 0;
		}
		if(grid[i-1][j]=='#'&&grid[i][j-1]=='#'){
			cout << "Impossible" << endl;
			return 0;
		}
		if(i+1==h && j+1==w){
			cout << "Possible" << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
	return 0;
}
