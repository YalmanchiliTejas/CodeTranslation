#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int P, Q;
	cin >> P >> Q;
	cout << setprecision(15) << (double) P*Q/(P+Q) << endl;
	return 0;
}
