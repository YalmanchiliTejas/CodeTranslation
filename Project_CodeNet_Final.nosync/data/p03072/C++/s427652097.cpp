#include <stdio.h>
#include <algorithm>
using namespace std;
using ll = long long;

int n, h, mh, cnt = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		if (mh <= h)
			cnt++;
		mh = max(mh, h);
	}
	printf("%d\n", cnt);
}