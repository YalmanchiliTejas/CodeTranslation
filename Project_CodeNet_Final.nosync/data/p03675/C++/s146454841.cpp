#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define Int const int &

const int N=2*(1e5)+1;

int f;
inline void read(int &p) {
	char c=getchar();
	f=1;
	while (c<48 || c>57) {
		if (c=='-') {
			f=-1;
		}
		c=getchar();
	}
	p=0;
	while (c>47 && c<58) {
		p=p*10+c-48;
		c=getchar();
	}
	p*=f;
}

int a[N], b[N];

int main(void) {
	int n;
	read(n);
	for (int i=1; i<=n; i++) {
		read(a[i]);
	}
	for (int j=n; j>0; j-=2) {
		printf("%d ", a[j]);
	}
	int j = n%2 ? 2 : 1;
	while (j<=n) {
		printf("%d ", a[j]);
		j+=2;
	}
	return 0;
}
