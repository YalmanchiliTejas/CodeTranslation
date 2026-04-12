#include <bits/stdc++.h>

#define MAXN 200013
#define EPS 1e-12
#define FST first
#define SCD second
#define INF 0x3f3f3f3f
#define PREV(x) (((x)==1)?n:((x)-1))
#define NEXT(x) (((x)==n)?1:((x)+1))
#define LOG(x) tb[(UI(x) * (UI)263572066) >> 27]

using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef pair<int, int> PA;

const UI tb[32] = {13, 0, 27, 1, 28, 18, 23, 2, 29, 21, 19, 12, 24, 9, 14, 3, 30, 26, 17, 22, 20, 11, 8, 13, 25, 16, 10, 7, 15, 6, 5, 4};

int n, m, tot;


int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#else
	// freopen("distance.in", "r", stdin);
	// freopen("distance.out", "w", stdout);
#endif
	int T = 1;
	for (int ci=1;ci<=T;++ci) {
		char s[100];
		scanf("%s",s);
		n = strlen(s);
		for (int i=0;i<n-1;++i) {
			if (*(s+i)=='A'&&*(s+1+i)=='C') {
				puts("Yes");
				return 0;
			}
		}
		puts("No");
	}
	return 0;
}