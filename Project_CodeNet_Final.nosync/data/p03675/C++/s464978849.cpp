#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MAXN = 200100;

int n, p[MAXN];
bool bio[MAXN];

int main() {
	scanf("%d",&n);
	REP(i, n) scanf("%d",&p[i]);
	for (int i = n - 1; i >= 0; i -= 2) {
		bio[i] = 1;
		printf("%d ",p[i]);
	}

	REP(i, n) if (!bio[i]) printf("%d ",p[i]);
	puts("");
	return 0;
}