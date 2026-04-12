#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 1e3+1;
const int MOD = 1e9 + 7;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FAILNO {printf("NO\n"); return 0;}
#define FAIL1 {printf("-1\n"); return 0;}

int N;

int main() {
#ifdef OJ
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif

	int ans = 0;
	int mx = 0;

	scanf("%d", &N);
	while(N--) {
		int h;
		scanf("%d", &h);
		if (h >= mx) ans++;
		mx = max(mx, h);
	}

	printf("%d\n", ans);

	return 0;
}

