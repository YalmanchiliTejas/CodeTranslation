#include <cstdio>
#include <algorithm>
#define LL long long
#define MOD 1000000007
using namespace std;

int r, g, b;

int main(){
	scanf("%d%d%d",&r,&g,&b);
	if((r*100+g*10+b)%4==0)printf("YES\n");
	else printf("NO\n");
	return 0;
}
