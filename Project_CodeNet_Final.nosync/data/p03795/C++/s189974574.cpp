#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;

	int pay = 800*N;
	int back = 200*(N/15);

	cout << pay - back << endl;

	return 0;
}
