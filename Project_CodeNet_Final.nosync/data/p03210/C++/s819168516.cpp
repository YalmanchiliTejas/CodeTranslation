#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ll long long
#define pair<int, int> pi;
#define MOD 1000000007
#define INF 2000000001

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int n, m, a, x, y, A[200001];
int main() {
	cin >> n;
	if (n == 3 || n == 7 || n == 5)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}