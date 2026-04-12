#include <stdio.h>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int y = N / 15;
	cout << 800 * N - 200 * y << endl;
}