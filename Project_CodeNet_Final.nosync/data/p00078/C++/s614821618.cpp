#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
	int i,j,k;
	int n;
	int a[15][15];

	while( cin >> n && n !=  0 ){
		k = 0;
		for( i = 0;i < 15;i++ ){
			for( j = 0;j < 15;j++ ){
				a[i][j] = 0;
			}
		}
		for( i = -n / 2;i <= n / 2;i++ )
			for( j = 0;j < n;j++ )
				a[(j + i + n) % n][(j - i + n) % n] = ++k;
		for( i = 0;i < n;i++ ){
			for( j = 0;j < n;j++ ) printf("%4d",a[i][j] );
			puts("");
		}
	}
	return 0;
}