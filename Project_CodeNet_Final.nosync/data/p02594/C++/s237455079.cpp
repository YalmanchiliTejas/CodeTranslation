#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FSP(x) fixed << setprecision(x)
using namespace std;
using ll = long long;
constexpr ll INF = LLONG_MAX;
const long double PI = acosl(-1);
void Yes() {cout << "Yes\n";}
void No() {cout << "No\n";}
void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//constexpr ll P = 1e9 + 7;
	//constexpr ll P = 998244353;

	ll x;
	cin >> x;
	if (x >= 30) Yes();
	else No();
}