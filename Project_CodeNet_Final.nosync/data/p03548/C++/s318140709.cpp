#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c, ans;
	scanf("%d%d%d", &a, &b, &c);
	ans = (a-c)/(b+c);
	printf("%d\n", ans);
	return 0;
}