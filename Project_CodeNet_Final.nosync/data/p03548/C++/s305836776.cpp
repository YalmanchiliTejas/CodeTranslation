#include <iostream>
#include <string>
using namespace std;

int main() {
	int length,width,shy;
	cin >> length;
	cin >> width;
	cin >> shy;
	cout << (length-shy)/(width+shy) << endl;
}