#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <deque>
#include <assert.h>
using namespace std;

#define ran(i, a, b) for ((i) = (a); (i) < (b); (i)++)
#define rep(i, a) ran ((i), 0, (a))
#define rep1(i, a) ran ((i), 1, (a)+1)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define _0 first
#define _1 second
#define _pb(x) push_back(x)
#define _mp(x, y) make_pair(x, y)
#if defined(SHIROKO1_LOCAL) && !defined(NDEBUG)
#define DEBUG(...) fprintf(stderr, "[DEBUG] " __VA_ARGS__)
#else
#define DEBUG(...) ((void)0)
#endif

int main()
{
	deque<int> a;
	int n;
	cin >> n;
	int rev = 0;
	while (n--) {
		int x;
		cin >> x;
		if (rev)
			a.push_front(x);
		else
			a.push_back(x);
		rev ^= 1;
	}
	if (rev) {
		for (auto it = a.rbegin(); it != a.rend(); it++)
			printf("%i ", *it);
	} else {
		for (auto it = a.begin(); it != a.end(); it++)
			printf("%i ", *it);
	}
	putchar('\n');
	return 0;
}
