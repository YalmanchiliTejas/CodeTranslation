#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	char a[1000];
	f(i, 1000)a[i] = 0;
	int k, s;
	int n, m;
	int x, y, z;
	int ans = 0;

	scanf("%s", a);
	n = strlen(a);

	f(i, n-1){
		if (a[i] == 'A'&&a[i + 1] == 'C')ans = 1;
	}

	if (ans==1)printf("Yes\n");
	else printf("No\n");

	return 0;
}