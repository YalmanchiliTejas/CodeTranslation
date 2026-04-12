// by DenyTianly
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int inf = 1 << 26;

int a[300005];

int main(){
	int n;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i ++ ) {
		scanf("%d", &a[i]);
	}
	
	for ( int i = n; i >= 1; i -= 2) {
		printf("%d ", a[i]);
	}
	for ( int i = n%2==0?1:2; i <= n; i += 2 ) printf("%d ", a[i]);
	puts("");

	return 0;
}
