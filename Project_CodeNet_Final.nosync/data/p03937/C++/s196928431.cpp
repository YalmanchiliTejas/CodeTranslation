#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <vector>
#include <set>

using namespace std;

#define ERROR_ID		0

#define PROCESS_ERROR(Condition)    \
{                                   \
		if (!(Condition))           \
		{                           \
			goto Exit0;             \
		}                           \
}

typedef unsigned char			BYTE;
typedef int						BOOL;
typedef unsigned long			DWORD;
typedef long long				LLONG;

inline int read() {
	int ret = 0, f = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0'&&ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}//快读优化

int main(int argc, char* argv[])
{
	int			nLine;
	int			nColumn;
	char		chWord;
	int			nCount			= 0;

	cin >> nLine >> nColumn;

	for (int i = 1; i<= nLine; i++)
	{
		for (int j = 1; j <= nColumn; j++)
		{
			cin >> chWord;

			if (chWord == '#')
			{
				nCount++;
			}
		}
	}

	if (nCount != nLine + nColumn - 1)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << "Possible" << endl;
	}
	return 0;
}