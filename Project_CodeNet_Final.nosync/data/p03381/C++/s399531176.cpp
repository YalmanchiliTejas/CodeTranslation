#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())



int n;
int a[200000];
int b[200000];
int c, d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n)b[i] = a[i];
	sort(b, b + n);
	c = b[n / 2 - 1];
	d = b[n / 2];


	rep(i,n) {
		if (a[i] <= c) {
			cout << d << endl;
		}
		else {
			cout << c << endl;
		}
	}


	return 0;
}