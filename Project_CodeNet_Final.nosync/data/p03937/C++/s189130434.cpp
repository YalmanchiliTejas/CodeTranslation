#include <bits/stdc++.h>

using namespace std;

int row, col,jmlJalan;
char lintasan[10][10];
bool hasil;

void floodFill(int row1 , int col1){
	if(row1==row&&col==col1){
		hasil=true;
		return;
	}else{
		if(lintasan[row1][col1]!='#'){
			return;
		}else{
			floodFill(row1+1,col1);
			floodFill(row1,col1+1);
		}
	}
}

int main(){

	cin>>row>>col;
	for(int x=1;x<=row;x++){
		for(int y=1;y<=col;y++){
			cin>>lintasan[x][y];
			if(lintasan[x][y]=='#'){
				jmlJalan++;
			}
		}
	}
	if(jmlJalan!=(row+col-1)){
		cout << "Impossible"<<endl;
		return 0;
	}
	floodFill(1,1);
	if(hasil==true){
		cout << "Possible"<<endl;
	}else{
		cout << "Impossible"<<endl;
	}



	return 0;
}
