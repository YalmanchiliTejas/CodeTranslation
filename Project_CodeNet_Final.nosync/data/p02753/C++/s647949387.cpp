#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
	string S;
	cin >> S;

	bool exist = false;
	if (!(S.at(0) == S.at(1) && S.at(1) == S.at(2))) exist = true;
	if (exist) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}