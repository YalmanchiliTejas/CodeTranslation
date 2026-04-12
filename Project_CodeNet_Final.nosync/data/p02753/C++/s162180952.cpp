#include <iostream>
using namespace std;

int main() {
	string s;
  	cin >> s;
  	bool half = false, other = false;
  	for(int i = 0; i < s.size(); i++) {
    	if(s[i] == 'A') {
        	half = true;
        } else {
        	other = true;
        }
    }
  	if(half && other) {
    	cout << "Yes";
    } else {
    	cout << "No";
    }
}