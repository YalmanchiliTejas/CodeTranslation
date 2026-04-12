#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long inf = 1000000000000;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
	int n, m;
	cin >> n >> m;
	if (n == m) cout << "Yes";
	else cout << "No";
	return(0);
}