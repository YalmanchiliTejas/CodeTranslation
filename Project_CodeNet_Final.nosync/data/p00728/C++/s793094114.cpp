#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
using namespace std;
int main() {
	while (true) {
		int n = 0;
		scanf("%d", &n);
		if (n == 0) break;
		vector<int> a;
		for (int i = 0;i < n;++i) {
			int b = 0;scanf("%d",&b );
			a.push_back(b);
		}
		sort(a.begin(), a.end());
		int num = 0;
		for (int i = 0;i < n;++i) {
			num += a[i];
		}
		num -= (a[0] + a[n - 1]);
		printf("%d\n", num/(n-2));
	}
}
