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
#include <cstdio>
#include <tuple>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
//**デバッグ準備**//
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//bitSearch, bitList, gcdlcm, isPrime, primeFactorize, Npow, divisor, modinv, dfs, bfs, eratos//
//dijkstra, WarshallFloyd, BellmanFord, UnionFind, COM, digitDP ,RMQ//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R;
ll MOD = 1000000007; ll INF = 1LL << 62; ll ans = 0; ll z = 0, o = 1;
vl flag, color, D; vll path;
int main() {
	cin >> N;
	vl A(N);
	for (i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	ll left = 0;
	ll right = N - 1;
	vl L, R;
	//最初にA[0]を真ん中に
	left = 1;
	ll count = 0;
	while (count < N-1) {
		if (count % 4 == 0) {
			L.push_back(A[right]);
			right--;
		}
		if (count % 4 == 1) {
			R.push_back(A[right]);
			right--;
		}
		if (count % 4 == 2) {
			L.push_back(A[left]);
			left++;
		}
		if (count % 4 == 3) {
			R.push_back(A[left]);
			left++;
		}
		count++;
	}
	reverse(L.begin(), L.end());
	debug(L,A[0],R);
	ll mini = INF;
	if (L.size() > 0) {
		for (i = 0; i < L.size() - 1; i++) {
			ans += abs(L[i] - L[i + 1]);
			mini = min(mini, abs(L[i] - L[i + 1]));
		}
		ans += abs(L[L.size() - 1] - A[0]);
		mini = min(mini, abs(L[L.size()-1] - A[0]));
	}
	if (R.size() > 0) {
		ans += abs(R[0] - A[0]);
		mini = min(mini, abs(R[0] - A[0]));
		for (i = 0; i < R.size() - 1; i++) {
			ans += abs(R[i] - R[i + 1]);
			mini = min(mini, abs(R[i] - R[i + 1]));
		}
	}
	ll p, q;
	if (L.size() > 0) {
		p = L[0];
	}
	else {
		p = A[0];
	}
	if (R.size() > 0) {
		q = R[R.size() - 1];
	}
	else {
		q = A[0];
	}
	ans += abs(p - q);
	mini = min(mini, abs(p - q));
	debug(ans, mini);
	ans -= mini;
	cout << ans;
}