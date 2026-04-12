#include <cstdio>
#include <string>

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	if (b < a) {
		printf("No");
	} else {
		printf("Yes");
	}
}