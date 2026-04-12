#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define F first
#define S second
#define int long long
#define mod 1000000007
#define all(v) v.begin(), v.end()
using namespace std;
int mypow(int a, int b, int c) {
	if (b == 0)return 1;
	if (b % 2)return mypow(a, b - 1, c)*a%c;
	int z = mypow(a, b / 2, c);
	return z * z%c;
}
signed main() {
	string s;
	cin >> s;
	if (s[0] != s[1] || s[1] != s[2] || s[0] != s[2]) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}