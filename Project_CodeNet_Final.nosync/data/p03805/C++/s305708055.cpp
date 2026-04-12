#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <functional>
#include <random>
#include <time.h>
#include <chrono>
#include <sstream>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define mod 1000000007
#define sort(s) sort(s.begin(), s.end());
#define reverse(s) reverse(s.begin(), s.end());
#define P pair<int,int>
#define valid(x,y,h,w) (0<=x&&x<h&&0<=y&&y<w)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
using namespace std;
int POW(int x, int y) { return int(pow(double(x), double(y))); }
double log(double a, double b) { return log(b) / log(a); }

//Vectorに同じ値が入っている→true
bool VectorIsSame(vector<int> a) {
	sort(a);
	rep(i, a.size() - 1) {
		if (a[i] == a[i + 1]) {
			return true;
		}
	}
	return false;
}

//vectorにある要素が含まれているか
bool vector_finder(std::vector<int> vec, int number) {
	auto itr = std::find(vec.begin(), vec.end(), number);
	size_t index = std::distance(vec.begin(), itr);
	if (index != vec.size()) { // 発見できたとき
		return true;
	}
	else { // 発見できなかったとき
		return false;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> t(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	n--;
	int ans = 0;
	rep(i, POW(n, n)) {
		int i2 = i;
		vector<int> x(n);
		rep(j, n) {
			x[j] = i2 % n + 1;
			i2 /= n;
		}
		if (VectorIsSame(x)) continue;
		bool flag = true;

		//if (x[0] == 2 &&
		//	x[1] == 3 &&
		//	x[2] == 4 &&
		//	x[3] == 5 &&
		//	x[4] == 6 &&
		//	x[5] == 1) {
		//	int as = 1;
		//}

		rep(j, n) {
			if (j == 0) {
				if (!vector_finder(t[0], x[j])) {
					flag = false;
					break;
				}
			}
			else {
				if (!vector_finder(t[x[j-1]], x[j])) {
					flag = false;
					break;
				}
			}
		}
		if(flag) ans++;
	}
	cout << ans << endl;
}

