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
#define MOD 1000000007
#define SORT(s) sort(s.begin(), s.end());
#define reverse(s) reverse(s.begin(), s.end());
#define P pair<int,int>
#define mp make_pair
#define valid(x,y,h,w) (0<=x&&x<h&&0<=y&&y<w)
//#define int ll
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ndx[8] = { 0,1,0,-1, 1,1,-1,-1 };
int ndy[8] = { 1,0,-1,0, 1,-1,-1,1 };
using namespace std;
int POW(int x, int y) { return int(pow(double(x), double(y))); }
double log(double a, double b) { return log(b) / log(a); }

template <class T>
void VecRowShow(vector<T> vec) {
	rep(i, vec.size()) {
		if (i != vec.size() - 1) cout << vec[i] << " ";
		else cout << vec[i] << endl;
	}
}



int main() {
	string s;
	cin >> s;
	if (s[0] == 'A' &&s[1] == 'A' && s[2] == 'A') {
		cout << "No" << endl;
	}
	else if (s[0] == 'B' &&s[1] == 'B' && s[2] == 'B') {
		cout << "No" << endl;

	}
	else {

		cout << "Yes" << endl;
	}
}

