#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
const int MaxN = 1e5;
const int oo = 1 << 30;
const int mod = 1e9 + 7;
typedef long long LL;

int n;
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		int x = n * 800;
		int cnt = n / 15;
		int ans = x - cnt * 200;
		printf("%d\n", ans);
	}
	return 0;
}