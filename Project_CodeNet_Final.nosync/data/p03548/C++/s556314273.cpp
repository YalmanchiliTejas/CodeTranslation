#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

int main()
{
	int x, y, z; cin >> x >> y >> z;
	int amari = x % (y + z);

	if(amari == 0 ) cout << x / (y + z) - 1<< endl;
	else
	{
		if (amari < z) cout << x / (y + z) - 1 << endl;
		else cout << x / (y + z) << endl;
	}
}