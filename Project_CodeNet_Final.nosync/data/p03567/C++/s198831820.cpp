#include <string>
#include <iostream>

using namespace std;

int main(){
	string s;

	cin >> s;

	for(int i=1; i < (int)s.size(); i++){
		if(s[i-1]=='A' && s[i]=='C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}