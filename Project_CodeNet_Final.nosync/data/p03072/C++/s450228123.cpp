#include<iostream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<math.h>
#include"boost/algorithm/string.hpp"

using namespace std;


int main(){


	/*Q2*/

	/*Q3*/

	/*Q2*/

	int h[20];
	int n;
	int count = 0;
	int max = 0;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> h[i];

		if (max <= h[i]){
			count++;
			max = h[i];
		}

	}

	cout << count << endl;
	return 0;


	/*Q1*/
	/*
	int a, b;
	cin >> a >> b;

	if (a == b){
	cout << a + b;
	}
	else{
	if (a < b){
	cout << b * 2 - 1;
	}
	else{
	cout <<  a * 2 - 1;
	}
	}

	return 0;
	*/
}