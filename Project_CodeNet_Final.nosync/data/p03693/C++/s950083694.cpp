#include <algorithm>
#include <iostream>
#include<string>
using namespace std;


int main()
{
	int X, A, B,C;
	cin >> X >> A >> B;
	C = 100 * X + 10 * A + B;
	if (C % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
    return 0;
}
