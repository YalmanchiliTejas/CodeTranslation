

#include <iostream>
#include <string>
#include<algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a = a - c;
	cout << a / (b + c) << endl;
    return 0;
}

