
#include <iostream>
using namespace std;


int main(){
	string input;
	cin >> input;
	
	if(input[0] == 'A' && input[1] == 'C'){
		cout << "Yes" << endl;
		return 0;
	}
	for(int i=0;i<input.size()-2;i++){
		if(input[i] == 'A' && input[i+1] == 'C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}