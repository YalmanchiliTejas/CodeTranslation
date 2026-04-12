#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_isu(void) {
	int x, y, z;
	cin >> x >> y >> z;

	int num = x/(y + z);
	int sub = x - (y + z) * num;
	if (sub < z) num--;
	cout << num << endl;

}

int main()
{
	b_isu();
    return 0;
}