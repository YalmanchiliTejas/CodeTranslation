#include <iostream>
#include <string>
using namespace std;

int main() {
	string eki, resul;
		cin >> eki;
	if (eki[0] == eki[1] && eki[1] == eki[2]) {
		resul = "No";
	}
	else {
		resul = "Yes";
	}
	cout << resul << endl;
	return 0;
}