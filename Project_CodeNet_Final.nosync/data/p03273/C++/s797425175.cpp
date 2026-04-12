#include <iostream>
#include <string>

using namespace std;

int main(void){
	int h,w;
	string a[100];
	int flagh[100] = {0};
	int flagw[100] = {0};
	int dh=0,dw=0;
	cin >> h >> w;
	int i,j;
	for(i=0;i<h;i++) cin >> a[i];
	//行ごとに見ていく
	int count;
	for(i=0;i<h;i++){
		count = 0;
		for(j=0;j<w;j++){
			if(a[i][j]=='#'){
				count = 1;
				break;
			}
		}
		if(count == 0){
			flagh[i] = 1; //i行目は全部白
			dh++;
		}
	}
	//列ごとに見ていく
	for(j=0;j<w;j++){
		count = 0;
		for(i=0;i<h;i++){
			if(a[i][j]=='#'){
				count = 1;
				break;
			}
		}
		if(count == 0){
			flagw[j] = 1; //i行目は全部白
			dw++;
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(flagh[i] == 0 && flagw[j] == 0) cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}