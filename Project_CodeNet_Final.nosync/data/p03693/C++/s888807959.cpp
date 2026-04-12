#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int r, g, b;
	int val;
	
	cin >> r >> g >> b;
	val = r * 100 + g * 10 + b;
	
	if(val % 4) cout << "NO" << endl;
	else cout << "YES" << endl;
	
	return 0;
}
	