#include <bits/stdc++.h>
#define REP(a, b) for(int a = 0; a < b; a++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 120;

int DP[10005][105][3];
string k;
short n;
short D, sek;

int rek(short pos, short d, short ter) {
	//cout << pos << ' ' << d << ' ' << ter << '\n';
	if (pos == n) {
		if (ter == 2) return 0;
		if (d == 0) return 1;
		else return 0;
	}
	int &ret = DP[pos][d][ter];
	if (ret != -1) return ret;
	ret = 0;
	if (d == 0) ret += 1;
	if (pos != 0) {
		if (ter == 0 || ter == 2) ret = (ret + rek(pos + 1, d, ter)) % MOD;
		else if (ter == 1) {
			if (k[pos] - '0' == 0) ret = (ret + rek(pos + 1, d, 1)) % MOD;
			else ret = (ret + rek(pos + 1, d, 0)) % MOD;
		}
	}
	for(short i = 1; i <= 9; i++) {
		//cout << i << " EA\n";
		if (ter == 0 || ter == 2) {
			sek = (d - i) % D;
			if (sek >= 0) ret = (ret + rek(pos + 1, sek, ter)) % MOD; 
			else ret = (ret + rek(pos + 1, sek + D, ter)) % MOD;
		}
		else if (ter == 1){
			if (k[pos] - '0' < i) {
				sek = (d - i) % D;
				if (sek >= 0) ret = (ret + rek(pos + 1, sek, 2)) % MOD; 
				else ret = (ret + rek(pos + 1, sek + D, 2)) % MOD;
			}
			else if (k[pos] - '0' == i) {
				sek = (d - i) % D;
				if (sek >= 0) ret = (ret + rek(pos + 1, sek, 1)) % MOD; 
				else ret = (ret + rek(pos + 1, sek + D, 1)) % MOD;
			}
			else {
				sek = (d - i) % D;
				if (sek >= 0) ret = (ret + rek(pos + 1, sek, 0)) % MOD; 
				else ret = (ret + rek(pos + 1, sek + D, 0)) % MOD;
			}
		}
	}
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k;
	n = k.size();
	cin >> D;
	memset(DP, -1, sizeof DP);
	cout << rek(0, D, 1) << '\n';
}