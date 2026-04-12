#include<set>
#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<random>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<functional>
#include<string.h>
#include<limits.h>
using namespace std;

int a[300000];
signed main() {
	int b = 10;//???????????°???????????????????????§????????¢
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		b -= 10;
		if (b < 0) { puts("no"); return 0; }
		b = max(b, a[i]);
	}
	b = 10;
	reverse(a, a + n);
	for (int i = 0; i < n; i++) {
		b -= 10;
		if (b < 0) { puts("no"); return 0; }
		b = max(b, a[i]);
	}
	puts("yes");
}