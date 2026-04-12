#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int INF = 1e15;
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

signed main() {
	int H, W;
	cin >> H >> W;
	vector<string>a(H);
	rep(i, H)cin >> a[i];
	vector<bool>yoko(H, false), tate(W, false);
	rep(i, H) {
		rep(j, W) {
			if (a[i][j] == '#')yoko[i] = true;
		}
	}
	rep(i, W) {
		rep(j, H) {
			if (a[j][i] == '#')tate[i] = true;
		}
	}
	rep(i, H) {
		if (!yoko[i])continue;
		rep(j, W) {
			if (!tate[j])continue;
			cout << a[i][j];
		}
		cout << endl;
	}
}