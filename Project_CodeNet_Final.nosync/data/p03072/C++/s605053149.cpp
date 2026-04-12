#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <utility>
#include <tuple>
#include <climits>
#include <algorithm>
#include <cstdlib>
#define FOR(i,m,n) for(int i = (m); i < (n); i++)
#define REP(i,n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<int> vint;

int main() {
	int n, h;
	scanf("%d", &n);
	int count{}, max{INT_MIN};
	for(int i = 0; i < n; i++) {
		scanf("%d", &h);
		if(h >= max) {
			max = h;
			count++;
		}
	}
	printf("%d\n", count);

}
