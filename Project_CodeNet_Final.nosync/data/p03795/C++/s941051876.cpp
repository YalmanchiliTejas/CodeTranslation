#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include<iomanip>
#include<cstdio>
	using namespace std;
	int main()
	{
		int N, x, y,sum;
		cin >> N;
		sum = 800 * N;
		y = N / 15;
		sum -= 200*y;
		cout << sum;
	}