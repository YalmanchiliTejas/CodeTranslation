#include <iostream>

using namespace std;

int main() {
  	char s[3];
  	for (int i = 0; i < 3; i++) {
     	cin >> s[i];
      	for (int j = 0; j < i; j++) {
          	if (s[i] != s[j]) {
              	cout << "Yes" << endl;
              	return 0;
            }
        }
    }
  	cout << "No" << endl;
  
	return 0;
}