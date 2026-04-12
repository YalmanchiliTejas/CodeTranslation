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
//#include "bits/stdc++.h"
using namespace std;
//using namespace std::vector;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
//#define M_PI 3.1415926535
#define huge 1000000007
typedef long long int ll;
ll gcd(ll a, ll b);
ll lcm(ll x, ll y);
ll bur(ll N, ll X);
bool IsPrime(int num);
bool dp[110][10010];
class UnionFind;

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
	ll E = 0;
	ll M = 0;
	ll K = 0;
	//ll T = 0;
	//ll M = 0;
	//ll h[400][400] = {};
	ll b[9] = { 1,7,4,5,3,2,9,6,8 };//順番の配列
	ll b2[9] = { 2,3,4,5,5,5,6,6,7 };//順番の配列

									 //ll aa[20][20] = {};//sortaf
	ll c2[9] = {};

	ll d[10] = {};//要素数

				  //ll v[3] = {};
				  //ll *c, *s, *n;
	string S, T, U[52];
	char fi[50], fv[50];

	ll count = 0;
	float count2 = 0;
	
	vector<int> sum2(5);
	ll min = 1000;
	ll max = 1;
	ll dist1 = 0;
	ll dist2 = 0;
	ll dist3 = 0;
	ll now = 0;
	int tmax = 9;
	int tmax2 = 0;
	//int flag = 0;
	char temp, head;
	//int is = 0;
	bool start = false;

	//char p;

	float all = 0;
	ll amr = 0;
	ll ket = 0;
	ll state = 0;
	bool down = true;

	//ll aa[3] = {10000,10000,10000}, bb[3] = { 10000,10000,10000 }, cc[3] = { 10000,10000,10000 };
	//ll an[3] = { 10000,10000,10000 }, bn[3] = { 10000,10000,10000 }, cn[3] = { 10000,10000,10000 };

	cin >> N;
	vector<int> sum(N);
	
	rep(i, 0, N) {
		cin >> sum[i];
	//	sum2[i] = sum[i];
	}
	
	rep(i, 0, N) {

		if (A <= sum[i]) {
			count++;
		}

		if (A < sum[i]) {
			A = sum[i];
		}
	}
	cout << count << endl;
	//rep(i, 0, N) {
	//	cin >> le[i];
	//}

	//sort(le.begin(),le.end());


	//cout << count << endl;
	//cout << dist1-dist2 << endl;
	/*vector<pair<int,int>> tr(N);


	rep(i, 0, N) {
	cin >> tr[i].first;
	count += tr[i].first;
	}


	rep(i, 0, N) {
	cin >> tr[i].second;
	count2 += tr[i].second;
	}


	if (count < count2) {
	cout << -1 << endl;
	return 0;
	}

	rep(i, 0, N) {

	if (tr[i].first < tr[i].second) {
	sum += tr[i].second - tr[i].first;
	niku++;
	}
	else {
	ov[all] += tr[i].first - tr[i].second;
	all++;
	}

	}

	sort(ov.begin(), ov.end(), greater<>());

	int xx = 0;

	while (sum > 0) {

	sum -= ov[xx];
	xx++;
	niku++;
	}*/

	//cout << niku << endl;


	//x = (ll *)malloc((N+1) * sizeof(ll));
	//c = (ll *)malloc((N) * sizeof(ll));
	//cin >> D >> G;
	//vector<pair<int,int>> tr(M);
	//vector<pair<int,int>> qes(Q);
	//sort(c.begin(), c.end());

	//cout << c[2] - c[1] << endl;


	/*A = N / 1000;
	N %= 1000;
	B = N / 100;
	N %= 100;
	C = N / 10;
	N %= 10;
	D = N;*/



	//cin >> N >> M;

	//vector<pair<int,int>> c(M);
	////vector<pair<int, int>> e(M);
	//vector<ll> d(M);

	//rep(i, 0, M) {
	//	cin >> c[i].first >> c[i].second;
	//	//e[i].first = c[i].first;
	//	//e[i].second = c[i].second;

	//}
	////sort(c.begin(), c.end());

	//

	//rep(i, 0, M) {

	//	
	//	
	//	rep(j, 0, M) {
	//		if (c[i].first == c[j].first && c[j].second < c[i].second) {
	//			d[i]++;
	//			//cout << j << endl;
	//		}
	//	}
	//	cout << std::setfill('0') << std::right << std::setw(6) << c[i].first;
	//	cout << std::setfill('0') << std::right << std::setw(6) << d[i]+1 << endl;
	//}

	return 0;

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
		fprintf(stderr, "引数エラーです。\n");
		return 0;
	}

	return (x * y / gcd(x, y));
}

