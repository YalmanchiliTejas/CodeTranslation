#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin >> str;
	for(int i = 1;i <= 2;i++){
		if(str[0] != str[i]){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
