#include<cstdio>

using namespace std;

int main(){
	int r, g, b; scanf("%d %d %d", &r, &g, &b);
	if((100 * r + 10 * g + b) % 4 == 0) puts("YES");
	else puts("NO");
	return 0;
}