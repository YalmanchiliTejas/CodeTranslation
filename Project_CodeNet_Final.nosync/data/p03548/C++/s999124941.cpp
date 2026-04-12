/*
 * main.cpp
 *
 *  Created on: 2020/04/09
 *      Author: SkAaO
 */

#include <iostream>

using namespace std;

int main(){
	int X, Y, Z;
	cin >> X >> Y >> Z;

	for(int i = 0;;i++){
		int lim_length = (Y + Z) * i + Z;
		if(lim_length > X){
			cout << i-1 << endl;
			break;
		}
	}

	return 0;
}


