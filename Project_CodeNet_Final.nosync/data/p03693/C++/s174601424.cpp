#include <cstdio>

using namespace std;

int a[4];

int x,y,z;

int main() {
	scanf("%d%d%d",&x,&y,&z);
	
	x = x*100+y*10+z;
	
	x%4==0? puts("YES"): puts("NO");
	return 0;
}