#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	char c;
	int a = 0, b = 0;
	for (int i = 0; i < 3; ++i) {
		scanf(" %c", &c);
		if (c == 'A') ++a;
		else ++b;
	}
	if (a && b) printf("Yes");
	else printf("No");
	return 0;
}