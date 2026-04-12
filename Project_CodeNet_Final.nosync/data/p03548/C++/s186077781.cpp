#include <cstdio>
using namespace std;
int main()
{
	long long  x,y,z;
	scanf("%lld%lld%lld",&x,&y,&z);
	printf("%lld",(x-z)/(y+z));
	return 0;
}