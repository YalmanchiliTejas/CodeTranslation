#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

signed main() {
	int n; scanf("%d", &n);
	deque<int>v;
	if (n % 2 == 0) {
		rep(i, n) {
			int a; scanf("%d", &a);
			if (i % 2 == 1)v.push_front(a);
			else v.push_back(a);
		}
	}
	else {
		rep(i, n) {
			int a; scanf("%d", &a);
			if (i % 2 == 1)v.push_back(a);
			else v.push_front(a);
		}
	}
	rep(i, n) {
		if (i)printf(" ");
		printf("%d", v[i]);
	}
	puts("");
}