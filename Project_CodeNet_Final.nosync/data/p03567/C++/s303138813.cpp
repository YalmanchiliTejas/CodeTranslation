#include <iostream>
using namespace std;
int main(){
	string str;
	cin >> str;
	for(int i=0;i<str.size()-1;i++){
		if(str[i]=='A'&&str[i+1]=='C'){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}