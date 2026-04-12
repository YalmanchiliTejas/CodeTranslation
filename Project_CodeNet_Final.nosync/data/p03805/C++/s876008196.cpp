#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<cstring>
using namespace std;

vector<int>rinsetu[8];
bool k[8];
int S = 0;
int a, b;
void saiki(int c) {
	bool d = true;
	for (int e = 0; e < a; e++) {
		if (!k[e])d = false;
	}
	if (d) { S++; return; }
	for (int i : rinsetu[c]) {
		if (!k[i]) {
			k[i] = true;
			saiki(i);
			k[i] = false;
		}
	}
}
int main() {
	cin >> a >> b;
	for (int c = 0; c < b; c++) {
		int d, e; scanf("%d%d", &d, &e); d--; e--;
		rinsetu[d].push_back(e); rinsetu[e].push_back(d);
	}
	k[0] = true;
	saiki(0);
	cout << S << endl;
}