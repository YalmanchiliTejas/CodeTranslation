#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
// #define DEBUG_MODE
#ifdef DEBUG_MODE
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int n, h[25], mx[25];
int main () { 
#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	mx[0] = h[0];
	for (int i = 1; i < n; i++) mx[i] = max(mx[i - 1], h[i]);
	int ans = 0;
	for (int i = 0; i < n; i++) ans += (mx[i] <= h[i]);
	printf("%d\n", ans);
}