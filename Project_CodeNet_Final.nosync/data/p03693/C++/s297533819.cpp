#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <map>
#include <vector>

using namespace std;

int BubSort(int x[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (x[j - 1] > x[j]) {  /* 前の要素の方が大きかったら */
				temp = x[j];        /* 交換する */
				x[j] = x[j - 1];
				x[j - 1] = temp;
			}
		}
	}
	return 0;
}

int main()
{
	int r, g, b = 0;


	cin >> r>>g >> b;
	
	if ((100 * r + 10 * g + b) % 4 == 0)
	{
		cout<<"YES" << endl;

	}
	else
	{
		cout << "NO" << endl;

	}
	system("pause");
	return 0;
}