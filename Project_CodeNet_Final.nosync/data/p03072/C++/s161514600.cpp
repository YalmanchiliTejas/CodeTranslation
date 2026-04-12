//============================================================================
// Name        : test1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	int h[100];
	for(int i=0;i<n;++i) cin >> h[i];

	int count = 1;
	int max = h[0];
	for(int i=1;i<n;++i){
		if(h[i]-max>=0){
			count += 1;
			max = h[i];
		}
	}

	cout << count << endl;


}
