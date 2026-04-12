#include <iostream>
using namespace std;

int main() {
	int n, ans;
	scanf("%d", &n);
	
	ans = 800 * n - n / 15 * 200;
	
	printf("%d", ans);
	return 0;
}