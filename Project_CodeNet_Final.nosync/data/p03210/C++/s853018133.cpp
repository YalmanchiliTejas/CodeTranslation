#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int main(){
	scanf("%d", &n);
	if(n == 3 || n == 5 || n == 7) puts("YES");
	else puts("NO");
	return 0;
}