#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int iinf = 1 << 29;
const long long linf = 1ll << 61;

#define nnm(x, y) (((y) + (x) % (y)) % (y))
template<typename T> inline T gcd(T x, T y) { if(x < y) swap(x, y); T mod = x % y; if(mod == 0) return y; return gcd(y, mod); }
template<typename T> inline T lmc(T x, T y) { return x / gcd(x, y) * y; }

int main(int argc, char* argv[])
{
	ll K, A, B;
	scanf("%lld%lld%lld", &K, &A, &B);
	if (A >= K) printf("1\n");
	else if (A > B) printf("%lld\n", 2 * ((K - A) % (A - B) == 0 ? (K - A) / (A - B) : (K - A) / (A - B) + 1 ) + 1);
	else printf("-1\n");

	return 0;
}
