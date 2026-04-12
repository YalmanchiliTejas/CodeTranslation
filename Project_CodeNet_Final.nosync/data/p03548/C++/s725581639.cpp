#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int Maxn = 1e5 + 5;
int main ()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if ((x-z)%(y+z) == 0) printf("%d",x/(y+z));
	else printf("%d",x/(y+z)-1);
	return 0;
}