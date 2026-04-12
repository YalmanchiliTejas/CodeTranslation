#include <iostream>

using namespace std;

int main() {
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	printf((g*10+b)%4 ? "NO\n": "YES\n");
	return 0;
}
