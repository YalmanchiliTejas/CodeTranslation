#include <iostream>
#include <string>
using namespace std;
 
int main(){
	std::string s(3, 'c');
  	cin >> s;
  	int a=0;
  	int b=0;
  	for(int i=0; i<3; ++i){
    	if (s[i] == 'A'){
        	++a;
        }else if (s[i] == 'B'){
        	++b;
        }
      	if (a>0 && b>0){
        	cout << "Yes";
		return 0;
        }
    }
  cout << "No";
}