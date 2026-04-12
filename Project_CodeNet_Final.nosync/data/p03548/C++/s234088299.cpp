#include <cstdio>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ul;

const int iinf = 1 << 29;
const long long linf = 1l << 61;

int main(int argc, char* argv[])
{
	int X, Y, Z;
	scanf("%d %d %d", &X, &Y, &Z);
	printf("%d", (X - Z) / (Y + Z));

	return 0;
}
