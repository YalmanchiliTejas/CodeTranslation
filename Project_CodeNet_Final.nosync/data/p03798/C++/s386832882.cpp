#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const ll MOD = 1e9 + 7;
static const ll INF = (ll)1 << 62;

static const ll MAX_N = 100001;
static const ll MAX_M = 200001;

bool X[100005];
bool Y[100005];
ll n;

void calc() {
	rep(i, 1, n + 2) {
		if (Y[i] && X[i]) Y[i + 1] = Y[i - 1];
		else if (Y[i] && !X[i]) Y[i + 1] = !Y[i - 1];
		else if (!Y[i] && X[i]) Y[i + 1] = !Y[i - 1];
		else if (!Y[i] && !X[i]) Y[i + 1] = Y[i - 1];
	}
	if (Y[n] == Y[0] && Y[n + 1] == Y[1]) {
		rep(i, 0, n) 	cout << (Y[i] ? 'S' : 'W');
		cout << endl;
		exit(0);
	}
}

int main() {
	string s; cin >> n >> s;
	rep(i, 0, n)	X[i] = (s[i] == 'o') ? 1 : 0;
	X[n] = X[0];
	X[n + 1] = X[1];

	Y[0] = 1; Y[1] = 1;
	calc();
	Y[0] = 1; Y[1] = 0;
	calc();
	Y[0] = 0; Y[1] = 1;
	calc();
	Y[0] = 0; Y[1] = 0;
	calc();

	cout << -1 << endl;
	return 0;
}