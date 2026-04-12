#include<iostream>
#include<string>
#include<algorithm>
#include <map>  
#include <string.h>
#include <math.h>

using namespace std;

int x, y, z;

int main()
{	
	cin >> x >> y >> z;

	x -= (y + z * 2);

	int tmp=0;

	while (x >= 0) {
		tmp++;
		x -= (y + z);
	}

	cout << tmp << endl;

	return 0;
}