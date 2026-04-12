//#include <bits/stdc++.h>
//#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>
#include<cctype>
#include<fstream>


#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979
#define MAXI 7500000

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;
typedef string::const_iterator State;

int dy[5] = { 0,0,1,-1,0 };
int dx[5] = { 1,-1,0,0 ,0 };


int main(void) {

	int h, w;
	int yoko[101] = {}, tate[101] = {};

	cin >> h >> w;
	vector<string> a(h);

	FOR(i, 0, h-1) {
		cin >> a[i];
	}

	FOR(i, 0, h-1) {
		FOR(j, 0, w - 1) {
			if (a[i][j] == '#') {
				break;
			}
			if (j == w - 1) {
				tate[i] = 1;
			}
		}
	}

	FOR(i, 0, w - 1) {
		FOR(j, 0, h - 1) {
			if (a[j][i] == '#') {
				break;
			}
			if (j == h - 1) {
				yoko[i] = 1;
			}
		}
	}

	FOR(i, 0, h - 1) {
		if (tate[i] == 1) {
			continue;
		}
		FOR(j, 0, w - 1) {
			if (yoko[j] == 1) {
				continue;
			}
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}