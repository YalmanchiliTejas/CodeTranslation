#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int n, t, e, x;
	scanf("%d%d%d", &n, &t, &e);

	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);

		for(int s = 0; s <= t + e; s += x){
			if(abs(t - s) <= e){
				printf("%d\n", i);
				return 0;
			}
		}
	}

	puts("-1");
}