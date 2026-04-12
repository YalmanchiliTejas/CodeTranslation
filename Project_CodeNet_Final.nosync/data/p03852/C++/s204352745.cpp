#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	
  	int a = 0;
	for(int i = 0; i < str.size();i++){
		if(str.at(i) == 'a'){	
    		cout << "vowel" << endl;
        }
      	else if(str.at(i) == 'e'){
         	cout << "vowel" << endl;
        }
      	else if(str.at(i) == 'i'){
          	cout << "vowel" << endl;
        }
      	else if(str.at(i) == 'o'){
         	cout << "vowel" << endl;
        }
      	else if(str.at(i) == 'u'){
          	cout << "vowel" << endl;
        }
      	else{
     		cout << "consonant" << endl;
        }
    }
}