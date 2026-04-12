#include <iostream>
using namespace std;
main () {
	string s;
  	int benar = 0, benar1 = 0;
  	cin>>s;
  	for (int i=0;i<s.length();i++) {
    	if (s[i] == 'A') {
        	benar++;
        } else if (s[i] == 'B') {
        	benar1++;
        }
    }
  
  if (benar > 0 && benar1 > 0) {
  	cout<<"Yes"<<endl;
  } else {
  	cout<<"No"<<endl;
  }
}