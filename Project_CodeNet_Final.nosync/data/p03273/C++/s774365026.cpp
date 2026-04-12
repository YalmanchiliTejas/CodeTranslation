

#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

int main() {

	int h, w;
	cin >> h >> w;

	vector<vector<char>> a(h);

	for (int i = 0; i < h; ++i)a[i].resize(w);

	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	vector<vector<bool>> b(h);

	for (int i = 0; i < h; ++i)b[i].resize(w);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; j++) {
			b[i][j]=false;
		}
	}

	for (int i = 0; i < h; ++i) {

		bool ok = true;

		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#')ok = false;
		}

		if (ok ==true) {
			for (int k = 0; k < w; k++) {
				b[i][k] = true;
			}
		}
	}

	for (int j = 0; j < w; ++j) {

		bool ok = true;

		for (int i = 0; i < h; i++) {
			if (a[i][j] == '#')ok = false;
		}

		if (ok == true) {
			for (int k = 0; k < h; k++) {
				b[k][j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		bool isNeedBR = false;
		for (int j = 0; j < w; j++) {
			if (b[i][j] == false) {
				cout << a[i][j];
				isNeedBR = true;
			}
		}
		if (isNeedBR) {
			cout << endl;
		}
		
	}
}
