#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,ab_half;
	int x,y;
	int res = 1;

	cin >> a >> b >> ab_half >> x >> y;

	int block = min(x,y);

	//half is high
	if(ab_half*2 > a+b) res = (a+b) * block;
	//hals is cheap
	else res = (ab_half*2) * block;

	if (x>y)
	{
		int comp = x - block;
		if (comp*a < comp*(ab_half*2)) res += comp*a;
		else res += comp*(ab_half*2);

		cout << res << "\n";
	}

	else if (x<y)
	{
		int comp = y - block;
		if (comp*b < comp*(ab_half*2)) res += comp*b;
		else res += comp*(ab_half*2);
		
		cout << res << "\n";
	}

	else
	{
		cout << res << "\n";
	}

	return 0;
}