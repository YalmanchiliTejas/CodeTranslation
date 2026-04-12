#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
double dot(complex<double> a, complex<double> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real()*a.real() + a.imag()*a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(cosine);
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa > now_min) {
					now_min = goa;
					now_go = i;
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
long long size_of_beaf[2000] = {};
long long size_of_all[2000] = {};
long long calc(long long a, long long b) {
	if (a == 0) {
		assert(b == 0 || b == 1);
		if (b == 0) return 0;
		return 1;
	}
	if (b <= 1) return 0;
	b--;
	if (b <= size_of_all[a - 1]) {
		return calc(a - 1, b);
	}
	long long ans = size_of_beaf[a - 1];
	b -= size_of_all[a - 1];
	b--;
	ans++;
	if (b <= size_of_all[a - 1]) {
		return calc(a - 1, b) + size_of_beaf[a-1] + 1LL;
	}
	ans += size_of_beaf[a - 1];
	b -= size_of_all[a - 1];
	b--;
	assert(b == 0);
	return ans;
}
int main(){
#define int long long
	long long n, x;
	cin >> n >> x;
	size_of_beaf[0] = 1;
	size_of_all[0] = 1;
	for (int i = 0; i < n+1; ++i) {
		size_of_beaf[i + 1] = size_of_beaf[i] * 2 + 1;
		size_of_all[i + 1] = size_of_all[i] * 2 + 3;
	}
	cout << calc(n, x) << endl;
	return 0;
}