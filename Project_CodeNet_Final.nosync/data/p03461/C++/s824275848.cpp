#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<random>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
#include<string.h>
#include<iostream>
#define p pair<int,int>
#define P pair<int,p>
using namespace std;

int d[202];
vector<P>V;
int k[10][10];
signed main() {
	int a, b; cin >> a >> b;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> k[i][j];
		}
	}
	for (int i = 0; i < 100; i++) {
		V.push_back({ -1,{i,i + 1} });
	}
	for (int i = 0; i < 100; i++) {
		V.push_back({ -2,{ 101+i,i + 102 } });
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 101; j <= 201; j++) {
			int MAX = 0;//余裕の最大値
			for (int k = 0; k < a; k++) {
				for (int l = 0; l < b; l++) {
					MAX = max(MAX, ::k[k][l] - i*(k + 1) - (201 - j)*(l + 1));
				}
			}
			V.push_back({ MAX,{i,j} });
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			memset(d, 0x3f, sizeof(d));
			d[0] = 0;
			priority_queue<p>Q;
			Q.push({0,0});
			while (Q.size()) {
				p t = Q.top(); Q.pop();
				if (d[t.second] < t.first)continue;
				for (P u : V) {
					if (u.second.first == t.second) {
						int h = 0;
						if (u.first >= 0) {
							h = u.first;
						}
						else if (u.first == -1) {
							h = i + 1;
						}
						else { h = j + 1; }
						if (d[u.second.second] > t.first + h) {
							d[u.second.second] = t.first + h;
							Q.push({t.first+h,u.second.second });
						}
					}
				}
			}
			if (d[201] != k[i][j]) {
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");
	cout << 202 << " " << V.size()<< endl;
	for (P i : V) {
		if (i.first == -1) {
			cout << i.second.first + 1 << " " << i.second.second + 1 << " X" << endl;
		}
		else if (i.first == -2) {
			cout << i.second.first + 1 << " " << i.second.second + 1 << " Y" <<endl;
		}
		else {
			cout << i.second.first + 1 << " " << i.second.second + 1 << " " << i.first<< endl;
		}
	}
	cout << 1 << " " << 202 << endl;
}