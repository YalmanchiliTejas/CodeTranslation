#include <iostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;



int main()
{
	int n,hPre=0,h,ans=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (hPre <= h)ans++;
		hPre = max(hPre, h);
	}
	cout << ans << endl;
}