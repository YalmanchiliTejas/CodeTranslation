#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
#include <cstdlib>

using namespace std;

inline int to_int(string s) {int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string to_str(T x) {ostringstream sout; sout << x; return sout.str();}

typedef pair<int, int> P;
typedef long long ll;

const int INF = 1 << 30;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int y)
{
	return ((y%4==0&&y%100!=0)||y%400==0);
}

#define debug(a, b, c) for(int i = 0; i < b; i++){for(int j = 0; j < c; j++){printf("%3d", a[i][j]);}puts("");}puts("-----------------------------------------");

int main()
{
	int len, squ[16][16];

	while(cin >> len)
	{
		if(!(len%2) || len == 0) break;

		for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				squ[i][j] = -1;
			}
		}

		int ny = (len / 2) + 0.5;
		int nx = ny - 1;
		int num = 0;

		squ[len][len-1] = num;
		++num;

		for(int i = 0; i < len*len; i++)
		{
			int dx = nx+1, dy = ny+1;
			while(1)
			{
				if(dx >= len) dx = 0;
				if(dx < 0) dx = len - 1;
				if(dy > len-1) dy = 0;

				if(squ[dy][dx] == -1)
				{
					squ[dy][dx] = num;
					++num;
					nx = dx; ny = dy;
					break;
				}
				dx -= 1; dy += 1;
			}
		}

		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < len; j++)
			{
				printf("%4d", squ[i][j]);
			}
			puts("");
		}

	}
}