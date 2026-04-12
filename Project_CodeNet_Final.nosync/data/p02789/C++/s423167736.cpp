#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF 2 << 29
#define MOD 1000000007
#define Yes(f) puts((f)? "Yes" : "No")
#define YES(f) puts((f)? "YES" : "NO")
int gcd(int a, int b) {
	if (b != 0)return gcd(b, a % b);
	return a;
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

using Graph = vector<vector<int>>;

int main(){
	 int n, m; cin >> n >> m;
	 Yes(n == m);
}