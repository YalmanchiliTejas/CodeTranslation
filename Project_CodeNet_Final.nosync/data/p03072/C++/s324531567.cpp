//============================================================================
// Name        : abc124B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;

int main() {
	int N;
	int count = 0;
	int maxHeight = 0;
	cin >> N;
	for(int i = 0; i < N; ++i){
		int H;
		cin >> H;
		if(maxHeight <= H)++count;
		maxHeight = max(maxHeight, H);
	}

	cout << count << endl;
	return 0;
}
