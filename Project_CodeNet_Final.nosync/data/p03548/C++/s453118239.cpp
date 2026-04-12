#include<cmath>
#include<iostream>
#include<iomanip>
#include<iso646.h>
#include<string>
#include<vector>

#define For(counter,initial_value,conditions) for( int counter = initial_value; counter < conditions; counter++ )

using namespace std;
int
main()
{
	int x, y, z;
	cin >> x >> y >> z;
	int ans = (x - z) / (y + z);
	cout << ans << endl;
}