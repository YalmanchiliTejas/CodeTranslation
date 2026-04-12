#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	while(~scanf("%d %d %d", &a, &b, &c)) {
		printf("%d\n", (a - c) / (b + c));
	}
	return 0;
}