#include <iostream>

using namespace std;
int main(void)
{
	int C;
	int M = 0;
	int nc = 0;
	cin >> C;
	int H[C];
	for (int i = 0; i < C; ++i)
	{
		int H;
		cin >> H;
		if(M <= H)
		{
			nc++;
			M = H;
		}
	}
	cout << nc << "\n";
	return 0;
}