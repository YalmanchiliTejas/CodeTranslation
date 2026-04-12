#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int x, y, z, num = 0;
	scanf("%d %d %d", &x, &y, &z);
	for(int i = z; ;) {
		i = i + y + z;
		if(i > x) break;
		num = num + 1;
	}
	printf("%d\n", num);
}