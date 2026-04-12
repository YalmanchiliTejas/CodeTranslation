#include <cstdio>

using namespace std;

int main(){
	int r, g, b;
	scanf("%d", &r);
	scanf("%d", &g);
	scanf("%d", &b);

	if ((10 * g + b) % 4 == 0) {
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}