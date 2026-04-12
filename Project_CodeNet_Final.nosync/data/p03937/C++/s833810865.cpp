#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int r, c;
char board[12][12];

int possible() {
	if (board[0][0] != '#') return 0;
	if (board[r - 1][c - 1] != '#') return 0;
	int now = 0;
	for (int i = 0; i < r; i++) {
		if (board[i][now] != '#') return 0;
		for (int j = now; j < c; j++) {
			if (board[i][j] == '#') {
				board[i][j] = '.';
				now = j;
			}
			else break;
		}
	}

	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (board[i][j] == '#') return 0;
	return 1;
}

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", board[i]);
	}

	if (possible()) printf("Possible\n");
	else printf("Impossible\n");

	return 0;
}
