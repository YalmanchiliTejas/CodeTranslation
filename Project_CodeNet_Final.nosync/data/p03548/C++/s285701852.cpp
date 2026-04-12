#include<iostream>
#include<cmath>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include <utility>
using namespace std;
int a = 0, b = 0, c = 0, d = 0, e[60][60], f[120], g[101000], h[10100], counto = 0, ans = 0, x[100] = {}, y, z;
int64_t ab[10000] = {}, abc = 0, abcd = 0;
pair<int, int>manji[101] = {};
char rikka, toka[150][150] = {};
vector<int> train,code;
vector<char>aka,ao;
string saya, homu, kyok, mami[108], mado[100];
bool gg;
bool exist[1000];
int main() {
	cin >> a>>b>>c;
	for (int i = 1; a >= b+c*2; i++) {
		a = a - b;
		a = a - c;
		counto++;
	}
	cout << counto << endl;
	return 0;
}