#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define REP(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define INF 10000000
#define ll long long

using namespace std;

typedef pair<int, int> P;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int a, b, c, x, y;
int d;
ll int ans;

int main(){
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

	int l = min(a + b, c * 2);

	if(x > y){
		d = x - y;
		int m = min(a, c * 2);
		ans = l * y + m * d;
		printf("%d\n", ans);
	} else if (x < y){
		d = y - x;
		int m = min(b, c * 2);
		ans = l * x + m * d;
		printf("%d\n", ans);
	} else {
		ans = l * x;
		printf("%d\n", ans);
	}

	return 0;
}