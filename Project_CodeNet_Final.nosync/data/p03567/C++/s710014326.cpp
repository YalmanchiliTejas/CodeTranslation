#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(void){
	string s;
	cin >> s;
	for(int i=0;i<s.length()-1;i++){
		if(s.at(i) == 'A' && s.at(i+1)=='C'){
			cout << "Yes" << endl;
			return 0;
			break;
		}
	}
	cout << "No"  << endl;

}