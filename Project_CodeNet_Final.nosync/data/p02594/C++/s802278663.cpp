#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

inline ll read(){
	ll s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) w *= ch == '-' ? -1 : 1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}

inline void work(){
	n = read();
	if (n >= 30) puts("Yes");
	else puts("No");
}

int main(){
	work();
	return 0;
}