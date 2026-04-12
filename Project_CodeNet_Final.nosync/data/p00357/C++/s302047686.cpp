#include "bits/stdc++.h"

using namespace std;
#define INF 10000000
int main(void)
{
	int a; cin >> a;
	vector<int>arr(a * 2);
	vector<int>arr2(a * 2, 0);
	vector<int>arr3(a * 2, 0);
	for (int i = 1; i <= a; i++)
	{
		int b; cin >> b;
		b /= 10;
		arr[i] = b;
		arr[a * 2 - i] = b;
	}
	for (int i = 1; i < a * 2; i++)
	{
		arr2[i] = max(i + arr[i], arr2[i-1]);
	}
	int ddd = 1;
	for (int i = 0; i < a * 2; i++)
	{
		if (ddd>=a *2)
		{
			break;
		}
		ddd = arr2[ddd];
	}
	if (ddd >= a*2)
	{
		cout << "yes" << "\n";
	}
	else cout << "no" << "\n";
}

