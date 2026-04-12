#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.second < secondElof.second;
}
//**Snippetリスト**//
//rep, vin, all//
//gcdlcm, isPrime, eratos, modinv, bitSearch, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l, m, n; ll N, M, K, H, L;
ll MOD = 998244353; ll INF = 9999999999999; ll ans = 1;
vll flag, color; vll path; vl D; string S; vl P; vl W;
//***********//
ll battle(ll a, ll b) {
	ll big = max(a, b);
	ll small = min(a, b);
	if (W[abs(a - b) - 1] == 0) {
		return small;
	}
	else {
		return big;
	}
}
int main() {
	cin >> N;
	cin >> S;
	//cout << "hoge";
	ll L = S.length(); L++;
	W.resize(L-1);
	for (i = 0; i < L-1; i++) {
		W[i]=ctoi(S[i]);
	}
	//cout << L;
	for (i = 0; i < L; i++) {
		ll p;
		cin >> p;
		P.push_back(p);
	}
	//cout << "huga";
	vector<vll> list(N + 1);
	list[0].resize(1);
	list[0][0] = P;
	//k海戦目
	//ll size = L;
	for (k = 0; k < N; k++) {
		for (ll p = 0; p < list[k].size(); p++) {
			ll q = p * 2;
			list[k + 1].resize(list[k].size() * 2);
			ll size = list[k][p].size();
			for (ll i = 0; i < size - 1; i+=2) {
				//cout << i;
				//cout << list[k][p][i] << list[k][p][i + 1];
				//cout << battle(list[k][p][i], list[k][p][i + 1]);
				list[k + 1][q].push_back(battle(list[k][p][i], list[k][p][i + 1]));
				//cout << "aaa";
			}
			//cout << "hoge";
			//cout << "a-" << q;
			q++;
			for (ll i = 1; i < size-2; i+=2) {
				//cout << battle(list[k][p][i], list[k][p][i + 1]);
				list[k + 1][q].push_back(battle(list[k][p][i], list[k][p][i + 1]));
			}
			//cout << battle(list[k][p][size-1], list[k][p][0]);
			list[k + 1][q].push_back(battle(list[k][p][size-1], list[k][p][0]));
			//cout << "hoge";
			//cout << "a-" << q;
		}
		//size /= 2;
		//cout << "b" << endl;
	}
	for (i = 0; i < L; i++) {
		ll p = i;
		ll num = 0;
		//cout << p;
		ll P = L / 2;
		for (j = 0; j < N; j++) {
			if (p % 2 == 1) {
				num += P;
			}
			P /= 2;
			p /= 2;
		}
		//cout << num;
		cout << list[N][num][0] << endl;
	}
}
