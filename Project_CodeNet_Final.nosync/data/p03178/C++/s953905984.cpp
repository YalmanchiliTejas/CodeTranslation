#include<bits/stdc++.h>
using namespace std;
#define reg register
#define MaxLen 10003

const int Mod = 1e9 + 7;
char K[MaxLen];
int D, len, ans;
int f[2][105], a[MaxLen];

inline int inmod(int aa, int mo) {
	if(aa >= mo) aa %= mo;
	return aa;
}
inline void add(int &aa, int bb, int mo) {
	aa += bb;
	if(aa < Mod) aa += mo;
	if(aa > Mod) aa -= mo;
	return;
}

int main() {
	scanf("%s", K + 1), cin >> D;
	len = strlen(K + 1);
	for(reg int i = 1; i <= len; ++i)
		a[i] = K[i] - '0';
	for(reg int i = 0; i <= a[1]; ++i)
		++f[0][inmod(i, D)];
	int sum = a[1] % Mod;
	for(reg int i = 2; i <= len; ++i) {
		for(reg int j = 0; j < sum; ++j)
			for(reg int k = 0; k <= 9; ++k)
				add(f[1][inmod(j + k, D)], f[0][j], Mod);
		for(reg int k = 0; k <= 9; ++k) {
			if(k <= a[i])
				add(f[1][inmod(sum + k, D)], f[0][sum], Mod);
			else
				add(f[1][inmod(sum + k, D)], f[0][sum] - 1, Mod);
		}
		for(reg int j = sum + 1; j < D; ++j)
			for(reg int k = 0; k <= 9; ++k)
				add(f[1][inmod(j + k, D)], f[0][j], Mod);
		memcpy(f[0], f[1], sizeof f[0]), memset(f[1], 0, sizeof f[1]);
			sum = inmod(sum + a[i], D);
	}
	cout << f[0][0] - 1 << endl;
	return 0;
}