#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdlib.h>
#define ll long long
#define MOD_P 1000000007
using namespace std;



int main()
{
	int highest = 0;
	int n, sum = 0;
	int high;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> high;
		if (high >= highest) {
			sum++;
			highest = high;
		}
	}


	printf("%d", sum);

	return 0;
}