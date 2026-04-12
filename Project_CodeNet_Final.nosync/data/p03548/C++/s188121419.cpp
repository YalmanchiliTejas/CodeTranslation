#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y,z;
	cin >> x >> y >> z;
	int k = y + z + z,cnt = 1;
	while(k <= x)
	{
		if(k + y + z > x)
		{
			break;
		}
		else
		{
			k += y + z;
			cnt++;
		}
	}
    cout << cnt << endl;
	return 0;
}
