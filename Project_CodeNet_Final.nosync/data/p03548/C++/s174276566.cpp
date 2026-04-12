#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x, y, z;
	cin >> x >> y >> z;
	
	int width = x - z;
	
	int answer = width / (y + z);
	cout << answer << endl;

	return 0;
}