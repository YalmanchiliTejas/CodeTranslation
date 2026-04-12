#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string s;
	cin >> s;
	for(int i = 0; i < s.length()-1; i ++){
		if(s.substr(i,2) == "AC"){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}