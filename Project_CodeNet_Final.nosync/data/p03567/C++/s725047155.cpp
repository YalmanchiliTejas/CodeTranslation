#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>

using namespace std;

int main() {
	char S[6];
	int N,i;

	scanf("%s", S);
	N = strlen(S);
	for (i = 0; i < N - i;i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			printf("Yes\n"); return 0;
		}
	}
	printf("No\n"); return 0;
}