#include <iostream>
#include <string>

using namespace std;

int main(){
	int r,g,b;
	cin >> r >> g >> b;
	int num = (r * 10 + g) * 10 + b;
	string s =  num % 4 == 0 ? "YES" : "NO";
	cout << s << endl;
	return 0;
}