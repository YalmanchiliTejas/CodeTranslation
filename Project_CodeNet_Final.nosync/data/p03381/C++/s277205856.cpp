#include <bits/stdc++.h> 

using namespace std;

#define pii pair < int, int >
#define fr first
#define sc second
#define mk make_pair

const int N = (int)2e5 + 7;

int n;
pii a[N];
int ans[N];

main() {    
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].fr);
		a[i].sc = i;
	}
	sort(a + 1, a + n + 1);
	int mid1, mid2;
	mid1 = a[n / 2].fr;
	mid2 = a[n / 2 + 1].fr;
	int asd;
	for (int i = 1; i <= n; i++) {
		if (i <= n / 2) {
			asd = mid2;
		} else {
			asd = mid1;
		}
		ans[a[i].sc] = asd;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
}