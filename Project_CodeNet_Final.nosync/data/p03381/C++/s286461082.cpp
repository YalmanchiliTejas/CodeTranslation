#include <bits/stdc++.h>
using namespace std;

int n;
int x[200010];
int y[200010];
int l, r;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &x[i]);
		y[i] = x[i];
	}
	sort(y, y+n);
	l = y[n/2-1];
	r = y[n/2];
//	printf("%d %d\n", l, r);
	for(int i=0; i<n; ++i)
		if(x[i] <= l) printf("%d\n", r);
		else printf("%d\n", l);
}