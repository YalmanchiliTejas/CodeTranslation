#include <iostream>
#include <string>

using namespace std;

string s;

int main(){
    cin >> s;
    
    if(s[0] == s[1] and s[1] == s[2]){
    	cout << "No";
	}
	else{
		cout << "Yes";
	}


	return 0;
}

