#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin >> s;
	int a = s.size();
	for (int i = 0; i < a - 1; i++){
		if (s[i] == 'A'){
			if (s[i + 1] == 'C'){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}