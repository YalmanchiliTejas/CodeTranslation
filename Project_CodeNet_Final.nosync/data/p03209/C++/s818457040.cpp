#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int ly[60], pt[60];
int f(int n, int x) {
	int r = 0;
	x--;
	if (x <= 0)return r;
	if (x < ly[n - 1])return r+f(n - 1, x);
	x -= ly[n - 1]; r += pt[n - 1];
	if (x <= 0)return r;
	x--; r++;
	if (x <= 0)return r;
	if (x < ly[n - 1])return r+f(n - 1, x);
	x -= ly[n - 1]; r += pt[n - 1];
	return r;
}
signed main() {
	int n, x; cin >> n >> x;
	ly[0] = 1; pt[0] = 1;
	for1(i, n) {
		ly[i] = ly[i - 1] * 2 + 3;
		pt[i] = pt[i - 1] * 2 + 1;
	}
	cout << f(n, x) << endl;
}