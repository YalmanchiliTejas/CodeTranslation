#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int x, y;
	
	x=N*800;
	if(N >= 15) y = 200*(N/15);
	
	cout << x-y;
	cout << endl;
	
	return 0;
}