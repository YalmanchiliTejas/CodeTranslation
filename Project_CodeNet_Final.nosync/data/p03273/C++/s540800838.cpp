#include<stdio.h>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>     
#include <numeric>
#include <utility>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <limits>
#include <vector>
using namespace std;
#define ll long long
#define ld long double
#define rep(a,t) for(int a=0;a<t;++a) 
#define forever while(true)
#define Sort(a) sort(a.begin(),a.end())
#define Reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define print_double(val,a) cout << fixed << setprecision(a) << val << endl;
ll mod = 1e9 + 7;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;
	cin >> h >> w;
	char a[100][ 100];
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][ j];
		}
	}
	bool hs[200];
	bool ws[200];
	rep(i, 200) { hs[i] = ws[i] = false; }
	rep(j, w) {
		bool f = true;
		rep(i, h) {
			if (a[i][ j] != '.') { f = false; break; }
		}
		if (f) { ws[j] = true; }
	}
	rep(i, h) {
		bool f = true;
		rep(j, w) {
			if (a[i][ j] != '.') { f=false; break; }
		}
		if (f) { hs[i] = true; }
	}
	rep(i, h) {
		if (hs[i]) { continue; }
		rep(j, w) {
			if (ws[j]) { continue; }
			cout << a[i][ j];
		}
		cout << endl;
	}
	return 0;
}