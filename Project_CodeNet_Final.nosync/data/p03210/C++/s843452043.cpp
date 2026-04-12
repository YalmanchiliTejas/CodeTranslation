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
//#include "bits/stdc++.h"
using namespace std;
//using namespace std::vector;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)

#define huge 1000000007
typedef long long int ll;
ll gcd(ll a, ll b);

int main(void) {

	ll N = 0;
	ll A = 0;
	ll B = 0;
	ll C = 0;
	ll D = 0;
	ll M = 0;
	ll T = 0;
	//ll M = 0;
	ll h[1000] = {};
	ll b[100] = {};
	//ll c[100] = {};
	//ll d[100] = {};

	//ll v[3] = {};
	//ll *c, *s, *n;
	//string S,T,U[52];
	ll count = 10;
	ll count2 = 0;
	float sum = 0;
	ll min = 1000000000000;
	ll max = 0;
	ll smax = 0;
	ll max2 = 0;
	ll smax2 = 0;
	int tmax = 0;
	int tmax2 = 0;
	int flag = 0;
	char temp,head;
	//int is = 0;
	
	
	//char p;


	

	

	//cin >> S;
	
	//b = (ll *)malloc(M * sizeof(ll));
	//vector<pair<int,int>> ch(50);

	cin >> N;
	

	//x = (ll *)malloc((N+1) * sizeof(ll));
	//c = (ll *)malloc((N) * sizeof(ll));
	//cin >> D >> G;
	//vector<pair<int,int>> tr(M);
	//vector<pair<int,int>> qes(Q);
	//sort(c.begin(), c.end());
	
	//cout << c[2] - c[1] << endl;

	if (N == 7 || N == 5 || N == 3)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

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


	return y/b*x;
}

