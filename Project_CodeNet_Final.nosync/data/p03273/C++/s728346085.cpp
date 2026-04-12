#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;


int main()
{
	int H,W;
	cin>>H>>W;
	char masu[100][100];
	bool compColumnList[100];
	bool compRawList[100];
	for(int i = 0; i < 100; i++){
		compColumnList[i] = true;
	}

	for(int i = 0; i < H; i++){
		bool thisRawIsAllWhite = true;
		for(int j = 0; j < W; j++){
			cin>>masu[i][j];
			if( masu[i][j] == '#'){
				thisRawIsAllWhite = false;
				compColumnList[j] = false;
			}
		}
		if( thisRawIsAllWhite == true){	//compress this raw
			i--;
			H--;
		}
	}

	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(compColumnList[j] != true){
				cout<<masu[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}


