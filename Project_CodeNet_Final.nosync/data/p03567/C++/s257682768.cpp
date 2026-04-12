#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.length() - 1; i++){
		if(s.at(i) == 'A' && s.at(i+1) == 'C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}