#include <iostream>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	char a[H+1][W+1];
	bool complete;
	bool cmpH[H+1];
	bool cmpW[W+1];
	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++){
		cin >> a[i][j];
	}
	for(int i = 1; i <= H; i++){
		complete = true;
		for(int j = 1; j <= W; j++){
			if(a[i][j] == '#'){
				complete = false;
				break;
			}
		}
		if(complete) cmpH[i] = true;
		else cmpH[i] = false;
	}
	for(int j = 1; j <= W; j++){
		complete = true;
		for(int i = 1; i <= H; i++){
			if(a[i][j] == '#'){
				complete = false;
				break;
			}
		}
		if(complete) cmpW[j] = true;
		else cmpW[j] = false;
	}	
	for(int i = 1; i <= H; i++){
		if(cmpH[i]) continue;
		for(int j = 1; j <= W; j++){
			if(cmpW[j]) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
}
