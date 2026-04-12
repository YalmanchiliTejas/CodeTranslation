#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int N, T, E;
	
	scanf("%d %d %d", &N, &T, &E);
	
	for (int i = 0; i < N; i++){
		int x;
		scanf("%d", &x);
		for (int j = 1; x * j - T <= E; j++){
			if (abs(x * j - T) <= E){
				printf("%d\n", i + 1);
				return (0);
			}
		}
	}
	
	printf("-1\n");
	return (0);
}