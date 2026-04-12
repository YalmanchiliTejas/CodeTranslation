#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	if (-40 <= x && x <= 40) {
		if (x >= 30) {
			cout << "Yes";
		}
		else {
			cout << "No";
		}
	}	
	return 0;
}