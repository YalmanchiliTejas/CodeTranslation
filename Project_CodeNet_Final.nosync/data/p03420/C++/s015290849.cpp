#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;

int n, k, r1, r2, r3, b;
LL res;

int main() {
scanf("%d %d", &n, &k);
if (k == 0) {
	printf("%lld\n", n * 1LL * n);
	return 0;
}
res = 0;
for (b=k+1;b<=n;b++) {
	r1 = (n + 1) / b;
	r2 = (n + 1) % b;
	r3 = b - k;
	//printf("%d %d %d\n", r1, r2, r3);
	res += r1 * 1LL * r3;
	res += max(0, r2 - (b - r3));
}
printf("%lld\n", res);
return 0;
}

