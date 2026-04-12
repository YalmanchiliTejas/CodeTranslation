#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	printf("%d\n", 800 * n - 200 * (n / 15));
}