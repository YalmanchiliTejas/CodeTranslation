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
#define SORT(s) sort(s.begin(), s.end());
#define reverse(s) reverse(s.begin(), s.end());
#define P pair<int,int>
#define mp make_pair
#define valid(x,y,h,w) (0<=x&&x<h&&0<=y&&y<w)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
using namespace std;
int POW(int x, int y) { return int(pow(double(x), double(y))); }
double log(double a, double b) { return log(b) / log(a); }




int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) {
		cin >> h[i];
	}
	int ans = 0;
	rep(i, n) {
		rep(j, i) {
			if (h[j] > h[i]) {
				break;
			}
			if (j == i - 1) {
				ans++;
			}
		}
	}
	cout << ans + 1 << endl;
}

