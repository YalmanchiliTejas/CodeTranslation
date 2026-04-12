#include <cstring>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
const int INF=0x3fffffff;
using namespace std;

int main()
{
	int A, B, C, x, y;
	cin >> A >> B >> C >> x >> y;

	if (C * 2 >= A + B)
	{
		printf("%d", x * A + y * B);
		return 0;
	}

	int cCount, aCount;
	aCount = cCount = 0;
	if (x < y)	//保持x需求大
	{
		swap(x, y);
		swap(A, B);
	}
	
	cCount = y*2;
	x -= y;
	if (C * 2 > A) {
		aCount = x;
		printf("%d\n", cCount * C + aCount * A);
	}
	else
	{
		cCount += 2 * x;
		printf("%d\n", cCount * C);
	}
	return 0;
}