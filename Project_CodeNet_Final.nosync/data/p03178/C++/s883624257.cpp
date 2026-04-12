#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define debug(x) cerr << #x << " = " << x << endl;
#define SET(c, v) memset(c, v, sizeof c)
#define pi 3.14159265358979323846264338
#define all(S) (S).begin(), (S).end()
#define mod 1000000007LL
#define INF 0x3f3f3f3f
#define pf push_front
#define pb push_back
#define mk make_pair
#define MAX 10010
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef unsigned long long int ull;
ll pd[MAX][101][2], n, cnt;
string s;

ll solve(int k, int p, int sum) {
	if(k == (int)s.size() && !(sum % n)) return 1;
	if(k == (int)s.size()) return 0;
	ll &ans = pd[k][sum][p];
	if(ans != -1) return ans;
	int v = s[k] - '0';
	ans = 0;
	if(p) {
		for(int i = 0; i < v; i++)
			ans = (ans + solve(k+1, 0, (sum+i)%n)) % mod;
		ans = (ans + solve(k+1, 1, (sum+v)%n)) % mod;
	}
	else {
		for(int i = 0; i < 10; i++)
			ans = (ans + solve(k+1, 0, (sum+i)%n)) % mod;
	}
	return ans;
}

int main(int argc, char** argv) {
	cin >> s >> n;
	memset(pd, -1, sizeof pd);
	cout << ((solve(0, 1, 0) - 1) + mod) % mod << endl;
	return 0;
}
