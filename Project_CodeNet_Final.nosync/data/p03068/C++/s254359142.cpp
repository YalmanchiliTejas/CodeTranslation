#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 0xc0c0c0c0
#define NINF 0x3f3f3f3f

#define FOR(i, a, b) for((i)=a; i<b; ++(i))
#define EFOR(i, a, b) for((i)=a; i>b; --(i))

#define MLC(n, type) (type*)malloc(n*sizeof(type))
#define CLC(n, type) (type*)calloc(n, sizeof(type))

#define MAXN 11

void solver(int nStrLen, char *pcStr, int k) {
	if (pcStr == NULL) {
		return;
	}

	int i = 0;
	char c = pcStr[k-1];

	FOR(i, 0, nStrLen) {
		if (pcStr[i] != c) {
			pcStr[i] = '*';
		}
	}

	printf("%s\n", pcStr);
}

int main() {
	int i,n,k;
	char a[MAXN] = {0};

	scanf("%d", &n);
	scanf("%s", a);
	scanf("%d", &k);

	solver(n, a, k);
	return 0;
}
