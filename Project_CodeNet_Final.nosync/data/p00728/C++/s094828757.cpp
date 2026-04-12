#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;


int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		int sum = 0, max_s = -1, min_s = 1001;
		for (int i = 0; i < n; ++i) {
			int s;
			scanf("%d", &s);
			sum += s;
			max_s = max(max_s, s);
			min_s = min(min_s, s);
		}

		sum = sum - max_s - min_s;
		printf("%d\n", sum/(n-2));
	}

	return 0;
}