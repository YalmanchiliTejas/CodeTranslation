#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	string s;
	cin >> s;
	int a = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A' && s[i+1] == 'C') a = 1;
	}
	if(a == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}