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
pair<int,int> calc(string a, int b) {
	int ans = 0;
	while (b < a.length() && a[b] >= '0'&&a[b] <= '9') {
		ans *= 10;
		ans += a[b] - '0';
		b++;
	}
	return make_pair(ans, b);
}
int compare(string a, string b) {
	int itr = 0;
	for (int i = 0; i < min(a.length(),b.length()); ++i) {
		if ((a[i] >= 'a'&&a[i] <= 'z') || (a[i] >= 'A'&&a[i] <= 'Z')) {
			if ((b[i] >= 'a'&&b[i] <= 'z') || (b[i] >= 'A'&&b[i] <= 'Z')) {
				if (a[i] > b[i]) {
					return 1;
				}
				else if (a[i] < b[i]) {
					return 0;
				}
			}
			else {
				return 1;
			}
		}
		else{
			if ((b[i] >= 'a'&&b[i] <= 'z') || (b[i] >= 'A'&&b[i] <= 'Z')) {
				return 0;
			}
			else {
				pair<int, int> as = calc(a, i),bs = calc(b,i);
				if (as.first < bs.first) return 0;
				else if (as.first > bs.first) return 1;
				i = as.second-1;
			}
		}
	}
	if (a.length() <= b.length()) return 0;
	return 1;
}
int bad[6000][6000] = {};
vector<int> a;
int next_search(int value,int bot) {
	int geko = bot - 1;
	int top = a.size() - 1;
	while (top - bot > 1) {
		int mid = (top + bot) / 2;
		if (a[mid] - a[geko] > value) {
			top = mid;
		}
		else bot = mid;
	}
	if (a[top] - a[geko] == value) return top;
	if (a[bot] - a[geko] == value) return bot;
	return -1;
}
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	int ans = 2;
	for (int i = 0; i < a.size(); ++i) {
		for(int q = i+1;q < a.size();++q){
			if (bad[i][q] == false) {
				int hiritu = a[q] - a[i];
				int cnt = 2;
				int now = q;
				while (now+1 < a.size()) {
					int gogo = next_search(a[q] - a[i], now+1);
					if (gogo == -1) break;
					bad[now][gogo] = true;
					now = gogo;
					cnt++;
				}
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
