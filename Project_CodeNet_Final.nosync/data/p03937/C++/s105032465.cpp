#include <iostream>
#include <vector>
using namespace std;

int main(){
	int h,w,i,j,count = 0;
	char a[10][10];
	cin >> h >> w;
	for(i = 0;i < 10;i++){
		for(j = 0;j < 10;j++){
			a[i][j] = '.';
		}
	}
	for(i = 1;i <= h;i++){
		for(j = 1;j <= w;j++){
			cin >> a[i][j];
		}
	}
	i = j = 1;
	a[i][j] ='.';
	while(1){
		if(i == h && j == w)break;
		if(a[i][j+1] == '#'){
			j++;
			a[i][j] = '.';
			continue;
		}
		else if(a[i+1][j] == '#'){
			i++;
			a[i][j] = '.';
			continue;
		}
		else if(a[i+1][j] == '.' && a[i][j+1] == '.'){
			break;
		}
	}

	for(i = 0;i < 10;i++){
		for(j = 0;j < 10;j++){
			if(a[i][j] == '#')count++;
		}
	}

	if(count == 0){
		cout << "Possible" <<endl;
	}
	else{
		cout << "Impossible" <<endl;
	}

	return 0;
}