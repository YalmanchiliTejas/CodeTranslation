#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main(void){

	int a[200000];
	int c, d;
	int k;
	int n, m;
	int s, t;
	int x, y, z;


	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}



	for (k=n-1; k >=0; k=k-2)printf("%d ", a[k]);
	k = (k + 3) % 2;
	for (; k<n-2; k=k+2)printf("%d ", a[k]);
	if(k<n)printf("%d\n", a[k]);

	return 0;
}

