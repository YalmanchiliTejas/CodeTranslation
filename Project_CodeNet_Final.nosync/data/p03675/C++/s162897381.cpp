#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N], b[N];

int main ()
{
	int n, st, sp = 1, f, fp;
	scanf("%d", &n);
	st = n / 2;
	f = fp = (n & 1) ? 1 : -1;
	scanf("%d", &a[st]);
	for(int i = 1; i < n; i++){
		scanf("%d", &a[st + sp * f]);
		if(f == fp) f = -f;
		else{
			f = -f; sp++;
		}
	}
	
	for(int i = 0; i < n; i++)
		printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
	
	
	return 0;
}