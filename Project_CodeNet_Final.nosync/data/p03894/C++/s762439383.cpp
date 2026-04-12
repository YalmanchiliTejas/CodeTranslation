#include<cstdio>
#include<cstring>
#include<cstdlib>

int main(void){
	int a[100000];
	int c;
	int x;
	int n;
	int w;
	int t;
	int p[100000];
	int q[100000];
	scanf("%d %d", &n, &t);
	for (int i = 0; i < t; i++){
		scanf("%d %d", &p[i], &q[i]);
		p[i]--;
		q[i]--;
	}
	for (int i = 0; i < 100000; i++)a[i] = 0;
	a[0] = 2;
	a[1] = 1;
x=0;
	for (int i = 0; i < t; i++){
		w = a[p[i]];
		a[p[i]] = a[q[i]];
		a[q[i]] = w;
		if (a[p[i]] == 2) x=p[i];
if(a[q[i]]==2)x=q[i];
			if (x > 0)a[x-1] = 1;
			if (x< n - 1)a[x+1] = 1;
	}
	c = 0;
	for(int i = 0; i < n; i++){
		if (a[i] > 0)c++;
}
	printf("%d\n",c);

	return 0;
}