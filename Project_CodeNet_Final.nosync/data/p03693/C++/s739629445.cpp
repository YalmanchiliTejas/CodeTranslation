#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a, b, c, sum;
	cin >> a >> b >> c;
	
	sum = b*10 + c;
	
	if(sum % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}