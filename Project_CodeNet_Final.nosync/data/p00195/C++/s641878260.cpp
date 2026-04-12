#include <cstdio>

using namespace std;

int main()
{
	int sa, sb;
	
	while (scanf("%d %d", &sa, &sb) && sa){
		int max = sa + sb;
		char ans = 'A';
		for (int i = 1; i < 5; i++){
			scanf("%d %d", &sa, &sb);
			if (max < sa + sb){
				max = sa + sb;
				ans = 'A' + i;
			}
		}
		printf("%c %d\n", ans, max);
	}
	
	return (0);
}