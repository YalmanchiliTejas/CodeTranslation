#include "iostream"
#include "cmath"
using namespace std;
int main()
{
	int n, h[20],ans=0,hmax=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> h[n];
		if (h[n] >= hmax)
		{
			hmax = h[n];
			ans++;
		}
	}
	cout << ans << endl;
}