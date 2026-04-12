#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#define int long long
#define rep(i,a,n) for (int (i)=(a);(i)<(n);(i)++)
using namespace std;
#define hash hush
typedef long long ll;
typedef long double ld;
int n, a[8];
signed  main() {
	ld a, b, c;
	cin >> a >> b;
	c = (1 / a) + (1 / b);
	printf("%.19LF\n", 1 / c);
	getchar(); getchar();
}