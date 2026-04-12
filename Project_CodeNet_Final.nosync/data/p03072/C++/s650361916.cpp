//great ocean view
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,h,ans = 0,max = 0;
	// int* h = new int[n];
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>h;
		if (h>=max)
		{
			max = h;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}