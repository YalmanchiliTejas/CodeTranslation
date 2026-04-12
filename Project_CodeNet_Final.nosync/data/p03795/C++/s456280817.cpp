#include <iostream>

using namespace std;

main(){
	int order;
	cin >> order;

	int sum = (order * 800) - (order / 15) * 200;

	cout << sum << endl;
}
