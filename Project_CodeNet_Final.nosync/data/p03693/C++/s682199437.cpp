#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	int a[100000];
	int b[100000];
	int c, d;
	int k;
	int n, m;
	int s, t;
	int x, y, z;


	scanf("%d %d %d", &x,&y,&z);

	c = 10 * y + z;
	if (c % 4 == 0) printf("YES\n");
	else printf("NO\n");

	return 0;
}