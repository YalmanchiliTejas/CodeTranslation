/*
 * wafuIroha.cpp
 *
 *  Created on: 2020/02/23
 *      Author: black
 */
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int total = 0;

	total = 800*n - 200*(n/15);

	cout << total << endl;

	return 0;
}
