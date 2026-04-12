#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <random>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define REP(i, n) for(int i=0; i<(n); i++)
#define LLREP(i,n) for(LL i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define SORT(x) sort(ALL(x))
#define REVE(x) reverse(ALL(x))
#define MP make_pair
#define PB push_back
#define INF INT_MAX

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> VVI;
typedef vector<vector<bool>> VVB;
typedef pair<int, int> PII;
typedef vector<pair<int, int>> VPII;
typedef queue<int> QI;
typedef long long LL;

int main() {
	int h, w, cnt = 0;
	cin >> h >> w;
	REP(i, h)REP(j, w) {
		char c; cin >> c;
		if (c == '#')cnt++;
	}
	printf(cnt == h + w - 1 ? "P" : "Imp");
	puts("ossible");
}