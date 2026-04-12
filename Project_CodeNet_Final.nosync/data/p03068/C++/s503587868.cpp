#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int n, k;
	string str;
	
	cin >> n;
	cin >> str;
	cin >> k;
	
	char key = str[k-1];
	
	for(int i=0 ; i<n; i++) {
		if(str[i] != key) {
			str[i] = '*';
		}
	}
	
	cout << str << endl;
	return 0;
}