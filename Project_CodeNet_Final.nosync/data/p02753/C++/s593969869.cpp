#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>
#include <functional>
#include <numeric>
#include <cassert>
#include <algorithm>
#include <functional>
#include <tuple>
#include <bitset>
#include <queue>
#include <map>
//#include "bits/stdc++.h"
using namespace std;
//using namespace std::vector;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define M_PI 3.14159265358979323846
#define huge 1000000
typedef long long int ll;
ll gcd(ll a, ll b);
ll lcm(ll x, ll y);
ll bur(ll N, ll X);
std::vector<ll> enum_div(ll n);
long long comb(int n, int r);
bool IsPrime(int num);
bool dp[110][10010];
class UnionFind;
using Graph = vector<vector<int>>;
ll co[300][300] = {};

//エラトステネスの篩
vector<bool> is_prime(huge);
vector<ll> P;
void Eratosthenes(const ll N)
{
	for (ll i = 0; i <= N; i++)
	{
		is_prime[i] = true;//初期化
	}
	for (ll i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			for (ll j = 2 * i; j <= N; j += i)
			{
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
}

//UF木
class UnionFind {
public:
	//親
	vector<int> Parent;

	//初期状態
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}

	int root(int A) {
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	//サイズ確認
	int size(int A) {
		return -Parent[root(A)];
	}

	int connect(int A, int B) {
		//root同氏をくっつける
		A = root(A);
		B = root(B);

		//結合済み
		if (A == B) {
			return false;
		}
		//大きいほうに小さいほうをくっつける
		if (size(A) < size(B)) swap(A, B);

		//Aのサイズ更新
		Parent[A] += Parent[B];
		//Bの親をAに
		Parent[B] = A;

		return true;
	}

};

int main(void) {

	ll N = 0;
	ll A = 0;
	ll B = 0;
	ll C = 0;
	ll D = 0;
	ll K = 0;
	//ll G = 0;
	ll M = 0;
	ll L = 1;
	ll Q = 1000000007;
	string S, T, U[52];
	char fi[50], fv[50];
	char board[4][4];
	ll count = 0;
	double count2 = 0;
	float n = 0;
	ll min = 300000000;
	ll max = 1, max2 = 0, max3 = 0, max4 = 0;
	float dist1 = 0;
	float dist2;
	float dist3 = 1;
	ll dist4 = 0;
	float now = 0;
	int tmax = 10000;
	int tmax2 = 0;
	//ll count = 0;
	//int flag = 0;
	//char temp, head, state;
	//int is = 0;
	bool start = false;
	ll left = 0, right = 0;

	cin >> S;

	if (S == "AAA" || S == "BBB") {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	
	cout << endl;
	//cout << max << endl;
	//cout <<  << endl;
	return 0;
}


std::vector<ll> enum_div(ll n)//nの約数を列挙
{
	vector<ll> res;
	for (ll i = 1; i*i <= n; ++i) {
		if (n % i != 0) continue;
		res.push_back(i);
		if (n / i == i) continue; // 上の行で追加済み。
		res.push_back(n / i);
	}
	return res;
}
ll bur(ll N, ll X) {
	ll pan = 1;
	ll pat = 1;
	ll burg = 0;



	if (X > burg) {
		if (N == 0)
			return pat;


		burg += pan;
		burg += bur(N - 1, X);
		burg += pat;
		burg += bur(N - 1, X);
		burg += pan;


	}

	return burg;

}

ll gcd(ll a, ll b) {

	/* 自然数 a > b を確認・入替 */
	if (a<b) {
		ll tmp = a;
		a = b;
		b = tmp;
	}
	ll x = b;
	ll y = a;
	/* ユークリッドの互除法 */
	ll r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}


	return y / b*x;
}





bool IsPrime(int num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

// 最大公約数を求める関数
ll lcm(ll x, ll y)
{
	if (x == 0 || y == 0)  // 引数チェック
	{
		//fprintf(stderr, "引数エラーです。\n");
		return 0;
	}

	return (x * y / gcd(x, y));
}

//combination
long long comb(int n, int r) {
	std::vector<std::vector<long long>> v(n + 1, std::vector<long long>(n + 1, 0));
	for (int i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (int j = 1; j < v.size(); j++) {
		for (int k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v[n][r];
}
