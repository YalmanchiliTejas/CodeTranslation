#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
typedef long double LD;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

/*
 test N = 2;

 */
int const MaxSize = 200000 + 5;
int A[MaxSize], sA[MaxSize], N;

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> N;

	LP(i, 0, N)
	{
		cin >> A[i];
		sA[i] = A[i];
	}

	sort(sA, sA + N);

	int eM = sA[N / 2];

	LP(i, 0, N)
	{
		if (A[i] < eM) {
			cout << eM << endl;
			//} else if (sA[i] > eM) {
		} else {

			cout << sA[N / 2 - 1] << endl;
		}
	}

	return 0;
}
