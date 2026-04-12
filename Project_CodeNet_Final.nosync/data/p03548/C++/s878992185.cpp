#include <bits/stdc++.h>
 
using namespace std;

int main(void)
{	
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x,y,z;

	cin >> x >> y >> z;

	x-=z;

	cout << x/(y+z) << '\n';

	return 0;
}