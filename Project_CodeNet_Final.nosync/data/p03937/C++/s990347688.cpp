#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<ctime>
#include<functional>
#define int long long
#define INT INT_MAX
#define LONG LLONG_MAX
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
typedef long long ll;
using namespace std;

ll GCD(ll a, ll b) {
	if (b == 0)return a;
	return GCD(b, a%b);
}

ll LCM(ll a, ll b) {
	return a / GCD(a, b)*b;
}

ll mypow(ll a, ll b, ll c) {
	if (b == 0)return 1;
	if (b % 2)return mypow(a, b - 1, c)*a%c;
	else return mypow(a, b / 2, c)*mypow(a, b / 2, c) % c;
}

signed main() {
	int a, b, x;
	cin >> a >> b;
	char c;
	f(i, a) {
		f(j, b) {
			cin >> c;
			if (c == '#') x++;
		}
	}
	if (x == a + b - 1) puts("Possible");
	else puts("Impossible");
	return 0;
}