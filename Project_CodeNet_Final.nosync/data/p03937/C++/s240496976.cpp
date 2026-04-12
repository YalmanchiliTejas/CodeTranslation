
#include <stdio.h>
#include <iostream>

#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>


using namespace std;


int main( int argc , char ** argv ){
	
	int H = 0 , W = 0;
	cin >> H >> W;

	vector<string> A;
	for(int i =0 ; i < H ; i++){
		string buf;
		cin >> buf;
		A.push_back(buf);
	}

	int count = 0;
	for(auto a : A){
		for(char _a : a){
			if(_a == '#') count ++;
		}
	}


	if(W+(H-1) != count) cout << "Impossible" << endl;
	else cout << "Possible" << endl;
}

