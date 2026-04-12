#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n;
	int a[20][20];
	while(scanf("%d", &n), n){
		memset(a, 0, sizeof a);
		int y = n / 2 + 1;
		int x = n / 2;
		for(int k = 1; k <= n * n; ++k){
			if(a[y][x] != 0){
				y = (y + 1) % n;
				x = (x + n - 1) % n;
			}
			a[y][x] = k;
			y = (y + 1) % n;
			x = (x + 1) % n;
		}
		
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%4d", a[i][j]);
			}
			puts("");
		}
	}
}