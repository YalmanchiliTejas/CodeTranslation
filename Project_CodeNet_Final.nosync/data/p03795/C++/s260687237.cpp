#include <iostream>
#include <string>


using namespace std; 

int main(){
	int N, x, y;
	cin >> N;
	x = 800 * N;
	if (N < 15){ y = 0; }
	else{ y = 200*(N - (N % 15)) / 15; }
	cout << x - y << endl;
	return 0;
}