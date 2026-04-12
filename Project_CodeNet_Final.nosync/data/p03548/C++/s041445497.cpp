#include<iostream>

using namespace std;

int main(void)
{
	int x,y,z;
	cin >> x >> y >> z;

	int ans;

	ans = x/(y+z);

	if(ans*(y+z)+z > x)ans--;

	cout << ans << endl;
}