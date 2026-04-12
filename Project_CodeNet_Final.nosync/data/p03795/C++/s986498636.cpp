#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int gain=N/15;
	cout << 800*N - gain*200 << endl;
	return 0;
}
