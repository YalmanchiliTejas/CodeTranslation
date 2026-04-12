#include <iostream>
using namespace std;
using uint = unsigned int;

int main() {
	uint N, M;
	cin >> N >> M;
	
	if(N == M) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}