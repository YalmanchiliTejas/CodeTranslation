#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

#define rep(i,n) for(long long i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long int ulli;

const ll INF = ll(1e18) + 1;

typedef struct {
	ll cost;
	ll damage;
}magic;

unsigned long long int a(ulli n, ulli b) {
	if (b <= 1) {
		return n;
	}
	else {
		return a(n * 2, b - 1);
	}
}

ll mina(ll a, ll b) {
	return (a > b) ? b : a;
}

void Main()
{
	ll n, m; cin >> n >> m;
	if (n == m) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	Main();
	return 0;
}