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

signed main() {
	int n;
	cin >> n;
	vector<string>S(n);
	vector<map<char, int>>m(n);
	rep(i, n) {
		cin >> S[i];
		for (auto j : S[i])m[i][j]++;
	}
	vector<int>v(26, INF);
	rep(i,n){
		rep(j, 26) {
			v[j] = min(v[j], m[i]['a' + j]);
		}
	}
	rep(i, 26) {
		char ch = 'a' + i;
		rep(j, v[i]) {
			cout << ch;
		}
	}
}