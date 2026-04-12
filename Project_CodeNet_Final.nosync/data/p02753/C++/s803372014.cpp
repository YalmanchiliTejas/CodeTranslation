#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  int cntB = 0, cntA = 0;
  
  getline(cin, str);
  
  for(int i = 0; i < 3; i++) {
    if (str[i] == 'A') {
    	cntA++;
    } else {
		cntB++;
    }
  }
  
  if(cntA != 0 && cntB != 0) {
	cout << "Yes" << endl;
  } else {
	cout << "No" << endl;
  }
  
  return 0;
}