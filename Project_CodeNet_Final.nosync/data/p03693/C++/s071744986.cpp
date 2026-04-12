#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c;
	int ans = 0;
	while(~scanf("%d%d%d",&a,&b,&c)){
		ans = a * 100 + b * 10 + c;
		if(ans % 4 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
