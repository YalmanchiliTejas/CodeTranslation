#include <iostream>

using namespace std;

int main(){
	char* s = (char*)calloc(4, sizeof(char));
	cin >> s;
	
	for(int i = 0; i < 3; i++){
		for(int j = i+1; j < 3; j++){
			if(s[i] != s[j]) {cout << "Yes" << endl; return 0;}
		}
	}
	cout << "No" << endl;
	return 0;
}