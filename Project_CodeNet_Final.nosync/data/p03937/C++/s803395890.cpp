#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include<cstdlib> 
#include<string>
#include<math.h>
#include<bitset>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
using namespace std;


int main(){

	int h,w;
	cin>>h>>w;
	char m[8][8];
	int sn=0;

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>> m[i][j];
			if(m[i][j]=='#' ){
				sn++;
			}
		}
	}
	//cout << sn << endl;
	if(sn==(h-1)+(w-1)+1){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}

	//while(1);

}
