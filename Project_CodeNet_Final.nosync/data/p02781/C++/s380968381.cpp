#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define S second
using namespace std;
int x[1000000];
string s;
int n;
int nCr(int a, int b) {
	if (a < b)return 0;
	int z = 1;
	for (int i = a; i > a - b; i--) {
		z *= i;
	}
	for (int i = 1; i <= b; i++) {
		z /= i;
	}
	return z;
}
int mutu(int x,int y) {
	if (y == n)return 1;
	if (x >= s.size())return 0;
	if (s[x] == '0') {
		return mutu(x + 1, y);
	}
	else {
		return nCr((int)s.size() - x - 1, n - y)*pow(9, n - y) + nCr((int)s.size() - x - 1, n - y - 1)*(s[x] - '1')*pow(9, n - y - 1) + mutu(x + 1, y + 1);
	}
}
signed main() {
	cin >> s >> n;
	cout<<mutu(0, 0)<<endl;
}