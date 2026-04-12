#include<iostream>
#include<string.h>

using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	char a[200][200];
	
	bool ux[200],uy[200];
	memset(a,0,sizeof(a));
	memset(ux,0,sizeof(ux));
	memset(uy,0,sizeof(uy));
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			cin >> a[i][j];
			if(a[i][j] == '#'){
				ux[j] = 1;
				uy[i] = 1;
			}
		}
	}
	
	for(int i = 0;i < h;i++){
		if(uy[i]){
			for(int j = 0;j < w;j++){
				if(ux[j]){
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	
	return 0;
}