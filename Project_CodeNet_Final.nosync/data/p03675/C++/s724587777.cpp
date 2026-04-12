#include <cstdio>
using namespace std;

int n, a[200100];

int main(){
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
		scanf("%d", a + i);
	for ( int i = n - 1; i >= 0; i -= 2 )
		printf("%d ", a[i]);
	for ( int i = n % 2; i < n; i += 2 )
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
