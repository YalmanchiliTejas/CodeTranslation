#include<cstdio>
#include<algorithm>
using namespace std;

#define ran 101101

int n;
int a[ran], f[ran];

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	
	int h = 0;
	for(int i=n-1;i>=0;i--) {
		int p = upper_bound(f, f+h, a[i]) - f;
		if (p>=h) f[h++] = a[i];
		else f[p] = a[i];
	}
	printf("%d\n", h);
	
	return 0;
}