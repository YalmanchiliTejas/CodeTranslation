#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	int N, K;
	char s[11];
	scanf("%d%s%d", &N, s, &K);
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] != s[K - 1]) {
			s[i] = '*';
		}
		printf("%c", s[i]);
		i++;
	}
	return 0;
}