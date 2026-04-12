#include <iostream>
using namespace std;

int main() {
	string s;
	int jud = 0;
	cin >> s;
	for(int i = 0;i < sizeof(s) - 1;i++){
		if(s[i] == 'A'){
			if(s[i + 1] == 'C'){
				cout << "Yes" << endl;
				jud = 1;
				break;
			}
		}
	}
	if(jud != 1){
		cout << "No" << endl;
	}
	return 0;
}