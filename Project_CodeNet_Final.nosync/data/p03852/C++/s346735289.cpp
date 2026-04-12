/*
 * wafuIroha.cpp
 *
 *  Created on: 2020/02/23
 *      Author: black
 */
#include <iostream>
using namespace std;

int main(){
	char a;
	cin >> a;

	if ((a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u')){
		cout << "vowel" << endl;
	}
	else{
		cout << "consonant" << endl;
	}

	return 0;
}
