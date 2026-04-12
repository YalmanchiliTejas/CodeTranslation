#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mems(p) memset(p,-1,sizeof(p))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define nl "\n"

const int mxN = 1e5;
const ll MOD = 1e9 + 7;

void fast()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	fast();
	int x;
	cin >> x;
	if (x >= 30) {
		cout << "Yes\n";
	}  else {
		cout << "No\n";
	}
}